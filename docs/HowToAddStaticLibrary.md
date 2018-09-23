# How to add Static Library

There are two methods to include static library, [adding it into arch library](#adding-it-into-arch-library) and [adding it as a new library](#adding-it-as-a-new-library).

## Adding it into arch library

Makefile or Make.defs in arch can include it for architecture specific library as mentioned below.  
Libarch.a includes new static library inside.
```
VPATH += <LIB_PATH>
EXTRA_LIBS += <LIB_PATH>/<LIB_NAME>.a
```
The *LIB_PATH* should be a relative path from *os/arch/arm/src*.

For example,
```
VPATH += chip/abc
EXTRA_LIBS += chip/abc/libnew.a
```

This change makes it add to TizenRT binary by Makefile which is at *os/arch/arm/src* folder.
```
$(BIN_DIR)/tizenrt$(EXEEXT): $(HEAD_OBJ) board/libboard$(LIBEXT)
	$(Q) echo "LD: tizenrt"
	$(Q) $(LD) --entry=__start $(LDFLAGS) $(LIBPATHS) $(EXTRA_LIBPATHS) \
		-o $(TIZENRT) $(HEAD_OBJ) $(EXTRA_OBJS) \
		--start-group $(LDLIBS) $(EXTRA_LIBS) $(LIBGCC) --end-group -Map $(TOPDIR)/../build/output/bin/tizenrt.map
```

## Adding it as a new library

TizenRT includes it as separated library, not merge it to existed library.

1. Add it in *Libtargets.mk*.  
    ```
    $(LIBRARIES_DIR)$(DELIM)<LIB_NAME>$(LIBEXT): <LIB_PATH>$(DELIM)<LIB_NAME>$(LIBEXT)
    	$(Q) install <LIB_PATH>$(DELIM)<LIB_NAME>$(LIBEXT) $(LIBRARIES_DIR)$(DELIM)<LIB_NAME>$(LIBEXT)
    ```

2. Add it in *FlatLibs.mk*, *ProtectedLibs.mk* and *KernelLibs.mk*.

    For kernel library,
    ```
    TIZENRTLIBS += $(LIBRARIES_DIR)$(DELIM)<LIB_NAME>$(LIBEXT)
    ```

    For user library,
    ```
    USERLIBS += $(LIBRARIES_DIR)$(DELIM)<LIB_NAME>$(LIBEXT)
    ```

    In flat build, there is no difference between TIZENRTLIBS and USERLIBS.  
    But in protected build and kernel build, TizenRT splits kernel space and user space. So, new static library should be included at appropriate space.

The *LIB_PATH* should be a relative path from *os*.
