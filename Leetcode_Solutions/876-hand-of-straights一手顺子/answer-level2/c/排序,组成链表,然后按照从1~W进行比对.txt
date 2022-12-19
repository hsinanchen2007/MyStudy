### 解题思路
先排序,记录每个数字出现的次数记录到链表结构
然后从链表中找到计数非0的节点开始1~W遍历比对,如果n + 1 == next(n)则计数减一,否则就return false

### 代码

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return *(int *)a < *(int *)b ? 0 : 1;
}

typedef struct _node
{
    int number;
    int count;
    struct _node *next;
} Node;

bool isNStraightHand(int *hand, int handSize, int W)
{
    if (W < 0 || W > handSize)
        return false;
    if (handSize % W != 0)
        return false;
    if (W == 1)
        return true;

    // STEP1: 先排序
    qsort(hand, handSize, sizeof(int), compare);

    // STEP2: 填充到链表中
    Node *list = (Node *)malloc(1 * sizeof(Node));
    Node *tmp = list;
    list->next = NULL;
    tmp->number = hand[0];
    tmp->count = 1;
    for (int i = 1; i < handSize; i++)
    {
        if (tmp->number == hand[i])
        {
            tmp->count++;
        }
        else
        { //(tmp->number != hand[i])
            tmp->next = (Node *)malloc(1 * sizeof(Node));
            tmp = tmp->next;
            tmp->number = hand[i];
            tmp->count = 1;
            tmp->next = NULL;
        }
    }

    tmp = list;
    Node *tmp2 = list;

    Node *tmp3 = list;
    // STEP3: 从链表头往后遍历
    while (tmp3)
    {
        if (tmp3->count != 0)
        {
            tmp = tmp3;
            for (int i = 0; i < W - 1; i++)
            {
                tmp2 = tmp->next;
                if (tmp2 == NULL)
                    goto LABEL_FALSE;
                if (tmp2->count == 0)
                    goto LABEL_FALSE;
                if (tmp->number + 1 != tmp2->number)
                {
                    goto LABEL_FALSE;
                }
                else
                {
                    tmp->count--; //如果相等,则count--
                }
                tmp = tmp->next;
            }
            tmp2->count--; //第W个count--
        }
        if (tmp3->count == 0)
        { // 如果tmp3计数为0,则tmp3向后跳下一个
            tmp3 = tmp3->next;
        }
    }

    // free list
    tmp = list;
    while (tmp)
    {
        Node *t = tmp->next;
        free(tmp);
        tmp = t;
    }

    return true;
LABEL_FALSE:
    // free list
    tmp = list;
    while (tmp)
    {
        Node *t = tmp->next;
        free(tmp);
        tmp = t;
    }

    return false;
}

// bool isNStraightHand(int *hand, int handSize, int W);
// int main()
// {
//     //int hand[9] = {1, 2, 3, 6, 2, 3, 4, 7, 8};
//     int hand[6] = {1, 1, 2, 2, 3, 3};
//     int W = 3;

//     if (isNStraightHand(hand, 6, W))
//         printf("TRUE\r\n");
//     else
//         printf("FALSE\r\n");
    
//     return 0;
// }

```