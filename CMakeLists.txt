cmake_minimum_required(VERSION 3.8)
project(ProjectManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON) #ui_XXX.h
set(CMAKE_AUTOMOC ON) #信号与槽的头文件和源文件生成 moc_XXX.cpp
set(CMAKE_AUTORCC ON) # 资源文件 qrc文件

# 找到包
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# 添加源文件
add_executable(${PROJECT_NAME} main.cpp ./ElaWidgetTools/include/ElaWidgetTools.qrc)

# 添加 LoginRegister 子项目
add_subdirectory(LoginRegister)

include_directories(
    ElaWidgetTools/include
)

# 链接库
target_link_libraries(${PROJECT_NAME} Qt6::Widgets LoginRegister
 ${CMAKE_CURRENT_SOURCE_DIR}/ElaWidgetTools/lib/ElaWidgetTools.lib
)

# 添加对 ElaWidgetTools.dll 的引用
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_SOURCE_DIR}/ElaWidgetTools/lib/ElaWidgetTools.dll
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)