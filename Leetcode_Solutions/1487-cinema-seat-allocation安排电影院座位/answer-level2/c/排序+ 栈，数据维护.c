### 解题思路
此处撰写解题思路

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#define MAX_LEN 10
int cmp(const void *a, const void *b)
{
    int *pa = *(int **)a;
    int *pb = *(int **)b;
    if (pa[0] != pb[0]) {
        return pa[0] - pb[0];
    }
    return pa[1] - pb[1];
}

typedef struct {
    int count;
    int stack[MAX_LEN];
}Stack;

void init(Stack *s)
{
    s->count = 0;
    memset(s, 0, sizeof(s->stack));
    return;
}

int push(Stack *s, int a)
{
    if (s->count == MAX_LEN) {
        return - 1;
    }

    s->stack[s->count] = a;
    s->count++;
    printf("push:%d %d \n", s->count, a);
    return 1;
}
int pop(Stack *s)
{
    if (s->count == 0) {
        return -1;
    }
    s->count--;
    int temp = s->stack[s->count];
    printf("pop:%d %d \n", s->count, temp);
    return temp;
}

int MaxCount(Stack s)
{
    int array[MAX_LEN + 1] = { 0 };
    int tol = 0;
    int tmp = pop(&s);

    while (tmp != -1) {
        printf("tmp : %d\n", tmp);
        array[tmp] = 1;
        tol += array[tmp];
        tmp = pop(&s);
    }

    if (tol == array[1] + array[10]) {
        return 2;
    }
    if (array[2] == 0 && array[3] == 0 && array[4] == 0 && array[5] == 0) {
        return 1;
    }
    if (array[4] == 0 && array[5] == 0 && array[6] == 0 && array[7] == 0) {
        return 1;
    }
    if (array[6] == 0 && array[7] == 0 && array[8] == 0 && array[9] == 0) {
        return 1;
    }
    return 0;
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    qsort(reservedSeats, (size_t)reservedSeatsSize, sizeof(reservedSeats[0]), cmp);
    Stack s;
    init(&s);
    int max = 0;
    int index = 1;
    int i;
    for (i = 0; i < reservedSeatsSize; i++) {
        if (reservedSeats[i][0] == index) {
            push(&s, reservedSeats[i][1]);
            printf("1-push:%d\n", reservedSeats[i][1]);
        } else if (i == 0) {
            max += (reservedSeats[i][0] - index) * 2;
            init(&s);
            printf(" 1--max:%d\n", max);
            index = reservedSeats[i][0];
            i--;
        } else {
            max += (reservedSeats[i][0] - index - 1) * 2;
            max += MaxCount(s);
            init(&s);
            index = reservedSeats[i][0];
            i--;
            printf(" 2--max:%d\n", max);
        }
    }
    max += MaxCount(s) + (n - index) * 2;
    printf("%d\n", max);
    return max;
}
```