### Copyright 2023 Peregrin

descrip = tree-viewer
product = tree
acronim = tw
install_path = /usr/local/bin/
cc = gcc

# Structure
build_dir = build
source_dir = src
t_source_dir = tst


# Source files
src = $(wildcard $(source_dir)/*.c)
t_src = $(wildcard $(t_source_dir)/*.c)
t_ign = main
# Object files
obj = $(subst $(source_dir)/,$(build_dir)/,$(src:.c=.o))
t_obj = $(subst $(t_source_dir)/,$(build_dir)/,$(t_src:.c=.o)) $(subst $(build_dir)/$(t_ign).o,,$(obj))
# Headers / libs 
libs = $(wildcard lib/*.h)

# ABSTRACT
.PHONY: clean vars install check

# Primary build
$(product): check $(obj) | build
	$(cc) $(obj) -o $(product) 

# Build test-suite
test-suite: $(t_obj) | build
	$(cc) $(t_obj) -o test-suite

$(build_dir)/%.o : $(t_source_dir)/%.c $(libs) | build
	$(cc) -c $< -o $@

$(build_dir)/%.o : $(source_dir)/%.c $(libs) | build
	$(cc) -c $< -o $@   

build:
	mkdir build

check: test-suite
	@echo "Run test-suite:" 
	@./test-suite

vars:
	@echo "obj = $(obj)"
	@echo "src = $(src)"
	@echo "t_src = $(t_src)"
	@echo "t_obj = $(t_obj)"

clean: | build
	@rm -rf $(build_dir)
	@rm $(product)
	@rm test-suite
	@echo "Directory cleaned!"

install: $(product) $(install_path)$(product)
	@cp $(product) $(install_path)$(product)
	@cp $(product) $(install_path)$(acronim)
	@echo "\nWe thank you for installing $(descrip)!"
	@echo "For the use type: [$(product)], or [$(acronim)]."
