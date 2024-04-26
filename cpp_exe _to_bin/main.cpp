#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // 元のファイル名と変換後のファイル名
    std::string originalFileName = "a.exe";
    std::string binaryFileName = "a_binary.bin";

    // バイナリデータを読み込むためのファイルストリームを開く
    std::ifstream originalFile(originalFileName, std::ios::binary);

    if (!originalFile.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    // バイナリデータを格納するためのバッファ
    std::vector<char> buffer((std::istreambuf_iterator<char>(originalFile)), std::istreambuf_iterator<char>());

    // バイナリデータを書き出すためのファイルストリームを開く
    std::ofstream binaryFile(binaryFileName, std::ios::binary);

    if (!binaryFile.is_open()) {
        std::cerr << "Error: Unable to create binary file." << std::endl;
        return 1;
    }

    // バッファの内容を書き出す
    binaryFile.write(buffer.data(), buffer.size());

    // ファイルを閉じる
    originalFile.close();
    binaryFile.close();

    std::cout << "Binary conversion successful." << std::endl;

    return 0;
}
