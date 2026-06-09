### 解题思路
![image.png](https://pic.leetcode-cn.com/46758cbaf483bd6a7a8d4b28dea583be9dbb08785b441793ce1c59d1cc738d96-image.png)

1. 所有product链表排序
2. 根据第一个待查字母，形成链表
3. 根据待查字母，去掉不匹配的链表
4. 每次循环输出当前字母对应的链表中的前三个

这个题本身没有复杂的算法，主要是处理的细节

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define OUT_SIZE 3

typedef struct NodeT {
    int index;
    struct NodeT* next;
} NodeList;

int Comp2Str(const void* a, const void* b)
{
    return strcmp(*(char**)a, *(char**)b);
}

char*** suggestedProducts(char** products, int productsSize, char* searchWord, int* returnSize, int** returnColumnSizes)
{
    char*** ret;
    NodeList* head = NULL;
    NodeList* tail = NULL;
    int i;
    int len;
    int wordSize = strlen(searchWord);

    *returnSize = 0;
    if (wordSize < 1) {
        return ret;
    }

    qsort(products, productsSize, sizeof(char*), Comp2Str);

    len = 0;
    for (i = 0; i < productsSize; i++) {
        if (searchWord[len] != products[i][len]) {
            continue;
        }
        if (head != NULL) {
            tail->next = malloc(sizeof(NodeList));
            tail = tail->next;
        } else {
            head = malloc(sizeof(NodeList));
            tail = head;
        }
        tail->index = i;
        tail->next = NULL;
    }

    ret = malloc(sizeof(char**) * wordSize);
    char** oneOut = NULL;
    int* Col = malloc(sizeof(int) * wordSize);
    memset(Col, 0, sizeof(int) * wordSize);
    NodeList* p = head;
    do {
        // output
        oneOut = malloc(sizeof(char*) * OUT_SIZE);
        p = head;
        for (i = 0; i < OUT_SIZE; i++) {
            if (p != NULL) {
                oneOut[i] = products[p->index];
            } else {
                break;
            }
            p = p->next;
        }
        Col[len] = i;
        ret[len] = oneOut;
        len++;

        // filter
        p = head;
        while ((p != NULL) && (p->next != NULL)) {
            // unmatch
            if (searchWord[len] != products[p->next->index][len]) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        // new head
        if ((head != NULL) && (searchWord[len] != products[head->index][len])) {
            head = head->next;
        }
    } while ((len < wordSize) && (head != NULL));

    *returnSize = wordSize;
    *returnColumnSizes = Col;
    return ret;
}

```