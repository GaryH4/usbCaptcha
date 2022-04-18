set(prj_incs
    "../components/include"
    )
set(prj_srcs
    "main.c"
    "../components/fonts.c"
    "../components/oled.c"
    "../components/genRandom.c"
    )

idf_component_register(INCLUDE_DIRS ${prj_incs}
    SRCS ${prj_srcs})