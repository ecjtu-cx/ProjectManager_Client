add_library(LoginRegister)
set(CMAKE_AUTOUIC ON) 
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
# 找到包
find_package(Qt6 REQUIRED COMPONENTS Widgets Network)

target_sources(LoginRegister 
	PRIVATE
	    # 添加源文件
		src/LoginWindow.cpp
		src/ServerCheckWindow.cpp
		# 添加头文件
		include/LoginWindow.h 
		include/ServerCheckWindow.h
 )
target_include_directories(LoginRegister
	PUBLIC
		include
)
# 链接 Qt Widgets
target_link_libraries(LoginRegister Qt6::Widgets Qt6::Network)