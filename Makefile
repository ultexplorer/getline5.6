program_name := main
source_dirs := .

source_dirs := $(addprefix ../,$(source_dirs))
search_wildcards := $(addsuffix /*.c,$(source_dirs))

$(program_name): $(notdir $(patsubst %.c,%.o, $(wildcard $(search_wildcards) ) ) )
	gcc  $^ -lm -o $@

VPATH := $(source_dirs)

%.o: %.c
	gcc -c -MD $(compile_flags) $(addprefix -I,$(source_dirs)) $<

cr:
	rm -r release

cd:
	rm -r debug

include $(wildcard *.d)


