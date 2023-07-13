#include <stdio.h>
#include <stdint.h>
#include <byteswap.h>

//네트워크 바이트 파일2개를 넣으면 호스트 바이트로 변경후 합을 출력하는 함수
uint32_t netsum(FILE *file1, FILE *file2){

    uint32_t num1, num2;

    //파일로부터 4바이트 크기를 1번 읽어와 num변수에 저장합니다.
    fread(&num1, sizeof(uint32_t), 1, file1);
    fread(&num2, sizeof(uint32_t), 1, file2);

    //NBO를 HBO로 변환해줍니다.
    num1 = bswap_32(num1);
    num2 = bswap_32(num2);

    // 덧셈을 해줍니다.
    uint32_t sum = num1 + num2;

    return sum;

}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: add-nbo <file1> <file2>\n");
        return 1;
    }

    FILE *file1 = fopen(argv[1], "rb");
    FILE *file2 = fopen(argv[2], "rb");

    if (!file1 || !file2) {
        printf("Failed to open file\n");
        return 1;
    }


    printf("sum : 0x%x\n", netsum(file1, file2));

    // Close the files
    fclose(file1);
    fclose(file2);

    return 0;
}
