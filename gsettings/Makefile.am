module_flags = -export_dynamic -avoid-version -module -no-undefined -export-symbols-regex '^g_io_module_(load|unload|query)'

giomodule_LTLIBRARIES = libgsettingsmateconfbackend.la
giomoduledir = $(GIO_MODULE_DIR)

libgsettingsmateconfbackend_la_SOURCES = \
	mateconfsettingsbackend-module.c \
	mateconfsettingsbackend.c        \
	mateconfsettingsbackend.h

libgsettingsmateconfbackend_la_CFLAGS = \
	-I$(top_srcdir) \
	-I$(top_builddir) \
	$(GSETTINGS_CFLAGS)

libgsettingsmateconfbackend_la_LDFLAGS = \
	$(module_flags)               \
	$(NULL)

libgsettingsmateconfbackend_la_LIBADD =        \
	$(top_builddir)/mateconf/libmateconf-2.la \
	$(GSETTINGS_LIBS)                   \
	$(NULL)

dist_bin_SCRIPTS = mateconf-gsettings-schema-convert
bin_PROGRAMS = mateconf-gsettings-data-convert

AM_CPPFLAGS = \
	-I$(top_srcdir)         \
	-I$(top_builddir)       \
	-DDATADIR=\"$(datadir)\" \
	$(GSETTINGS_CFLAGS)

mateconf_gsettings_data_convert_SOURCES = mateconf-gsettings-data-convert.c
mateconf_gsettings_data_convert_LDADD =              \
	$(top_builddir)/mateconf/libmateconf-2.la \
	$(GSETTINGS_LIBS)                   \
	$(NULL)

autostartdir = $(sysconfdir)/xdg/autostart
autostart_DATA = mateconf-gsettings-data-convert.desktop

man_MANS =                       \
	mateconf-gsettings-schema-convert.1 \
	mateconf-gsettings-data-convert.1 \
	$(NULL)

%.1 : %.xml
	xsltproc -nonet http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl $<

EXTRA_DIST = mateconf-gsettings-data-convert.xml mateconf-gsettings-schema-convert.xml mateconf-gsettings-data-convert.1 mateconf-gsettings-schema-convert.1 mateconf-gsettings-data-convert.desktop

dist-hook-local: $(BUILT_EXTRA_DIST)
	files='$(BUILT_EXTRA_DIST)';                      \
	for f in $$files; do                              \
	  if test -f $$f; then d=.; else d=$(srcdir); fi; \
	  cp $$d/$$f $(distdir) || exit 1; done

install-data-hook:
	if test -z "$(DESTDIR)" -a "$(GIO_QUERYMODULES)" != "no" ; then                         \
		$(GIO_QUERYMODULES) $(GIO_MODULE_DIR) ;                                         \
	fi

