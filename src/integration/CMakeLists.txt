######################################################
#            PROJECT  : MALT                         #
#            VERSION  : 1.1.0-dev                    #
#            DATE     : 02/2018                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

######################################################
#Generate file with full paths
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/malt.sh.in ${CMAKE_CURRENT_BINARY_DIR}/malt)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/malt-webview.sh.in ${CMAKE_CURRENT_BINARY_DIR}/malt-webview)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/malt-passwd.sh.in ${CMAKE_CURRENT_BINARY_DIR}/malt-passwd)

######################################################
#install
INSTALL(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/malt ${CMAKE_CURRENT_BINARY_DIR}/malt-webview ${CMAKE_CURRENT_BINARY_DIR}/malt-passwd
        DESTINATION bin/)
INSTALL(FILES MaltMPIRank.cpp DESTINATION share/malt)
