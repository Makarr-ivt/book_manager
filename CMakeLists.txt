cmake_minimum_required(VERSION 3.16)

project(book LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Список всех исходных файлов
set(SOURCES
    main.cpp
    Book.cpp
    BookManager.cpp
)

# Список всех заголовочных файлов
set(HEADERS
    Book.h
    BookManager.h
)

# Создание исполняемого файла со всеми исходными файлами
add_executable(book ${SOURCES} ${HEADERS})

# Установка для заголовочных файлов (опционально, если нужно устанавливать)
target_include_directories(book PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Установка программы
include(GNUInstallDirs)
install(TARGETS book
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
