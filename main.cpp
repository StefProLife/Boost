#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include <boost/crc.hpp>
#include <boost/uuid/detail/md5.hpp>

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
//        ”тилита должна иметь возможность через параметры командной строки указывать
//        Х директории дл€ сканировани€(может быть несколько)
//        Х директории дл€ исключени€ из сканировани€(может быть несколько)
//        Х уровень сканировани€(один на все директории, 0 - только указанна€ директори€ без вложенных)
//        Х минимальный размер файла, по умолчанию провер€ютс€ все файлы больше 1 байта.
//        Х маски имен файлов разрешенных дл€ сравнени€(не завис€т от регистра)
//        Х размер блока, которым производитс€ чтени€ файлов, в задании этот размер упоминаетс€ как S
//        Х один из имеющихс€ алгоритмов хэшировани€(crc32, md5 - конкретные варианты определить самосто€тельно), в задании эта функци€ упоминаетс€ как H
    try
    {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "Help screen")
            ("path, p", po::value<std::string>(), "directories to scan (there may be several)")
            ("ignore-path, ip", po::value<std::string>(), "directories to exclude from scanning (there may be several)")
            ("scan-level, sl", po::value<std::uint8_t>()->default_value(0), "scan level(one for all directories, 0 is only the specified directory without attachments)")
            ("minimum-file-size, mfs", po::value<uint64_t>()->default_value(8), "minimum file size, by default, all files larger than 1 byte are checked")
            ("masks-name-file, mnf", po::value<std::string>()->default_value(""), "masks of file names allowed for comparison")
            ("size-block-read, sbr", po::value<uint64_t>()->default_value(4), "the size of the block used to read files")
            ("algorithms-hashing, ah", po::value<std::string>()->default_value("md5"), "алгоритмов хэшировани€(crc32, md5");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << "\n";
            return 0;
        }

    }
    catch (const po::error& ex)
    {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}