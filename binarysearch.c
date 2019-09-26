// built-in header file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// customized header file
#include "boolean.h"

#define MAXARRAY 10000

/**
 * function Prototype
*/
int binarySearch(const int low, const int high, const int index, const int sortedArray[]);

int main() {
    int sortedArray[MAXARRAY + 1] = {0, };
    int index = 0;      // search value
    int size = 0;       // array size

    printf("please intput array size : ");
    scanf("%d", &size);

    if(size > MAXARRAY) {
        printf("overflow 발생!!\n");
        return 0;
    }

    for(int i = 0; i < size; i++) {
        sortedArray[i] = i;
    }

    printf("what number do you want to find : ");
    scanf("%d", &index);
    int checksize = sizeof(sortedArray) / sizeof(int);

    if(size > checksize) {
        printf("배열의 크기를 초과하였습니다!!\n");
        return 0;
    }

    // 찾는 값이 없으면
    if(binarySearch(0, size, index, sortedArray) != EOF) {
        printf("배열에 %d이 존재합니다.\n", index);
    }
    else {
        printf("찾는 값이 존재하지 않습니다.\n");
    }

    return 0;
}

int binarySearch(const int low, const int high, const int index, const int sortedArray[]) {

    // 배열에 찾는 값이 없으면 EOF return
    if(low > high) {
        return EOF;
    }
    else {
        int mid = (high + low) / 2;
        if(index == sortedArray[mid]) {
            return true;
        }
        // 2) Divide(분할) : 그렇지 않으면, 배열을 반으로 나누어서
        //  - index가 중앙에 위치한 항목보다 작으면 왼쪽 배열 반쪽을 선택
        if(index < mid) {
            binarySearch(low, mid-1, index, sortedArray);
        }
        //  - 그렇지 않으면 오른쪽 배열 반쪽을 선택한다.
        else {
            binarySearch(mid + 1, high, index, sortedArray);
        }

        // 3) Conquer(정복) : 선택된 반쪽 배열에서 index를 찾는다.
    }
}