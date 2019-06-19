#include <stdio.h>
#include "Darray.h"

int main(void)
{
    Vector vector;
    initVector(&vector);

    for(int i = 0; i < 10001; i++) {
        insertEnd(&vector, i);
    }

    int result = vectorGet(&vector, 4309);
    int length = vectorLength(&vector);

    printf("The result is: %d\n", result);
    printf("The length is: %d\n", length);
    for (int i = 800; i < 900; i++)
        printf("%d ", i);
    printf("\n");

    vectorSet(&vector, 100003, 100);
    int result2 = vectorGet(&vector, 100002);
    int result3 = vectorGet(&vector, 100003);
    printf("The result2 is: %d\n", result2);
    printf("The result3 is: %d\n", result3);
    vectorSet(&vector, 100, 50);
    int result4 = vectorGet(&vector, 100);
    printf("The result4 is: %d\n", result4);

    vectorFree(&vector);
    return 0;
}
