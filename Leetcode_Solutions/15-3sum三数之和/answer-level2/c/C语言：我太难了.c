### 解题思路
算法思路可以参考其他大神的。总体就是先排序，然后使用双指针进行查找符合条件的元素组合。其中要注意去重复。
C语言因为其特殊性，需要自己写一些数据结构。同样的问题C语言是最难的，大家没意见吧。
这里因为在查找元素组合的同时还需要知道一共有多少组，C语言没有像C++中可以自动扩充大小的标准库数据结构。这里我自己写了一个简单的单向链表。
但是题目要求返回二维数组，最后需要将链表中的数据转移到二维数组中。
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int a;
    int b;
    int c;
} Data;

typedef struct tagLink {
    Data            data;
    struct tagLink *next;
} LinkList;
static unsigned int g_LinkListLen = 0;
LinkList *          InitLinkList()
{
    LinkList *head = (LinkList *)malloc(sizeof(LinkList));
    if (head == NULL) {
        return head;
    }
    head->next = NULL;
    g_LinkListLen = 0;
    return head;
}
// 直接插在头结点，加快插入速度
LinkList *InsertElem(LinkList *head, Data data)
{
    if (g_LinkListLen == 0) {
        head->data = data;
        g_LinkListLen++;
        return head;
    }
    LinkList *pTemp = (LinkList *)malloc(sizeof(LinkList));
    if (pTemp == NULL) {
        return head;
    }
    g_LinkListLen++;
    pTemp->data = data;
    pTemp->next = head;
    return pTemp;
}

// 取指定pos的结点
LinkList *GetElem(LinkList *head, int pos)
{
    if (g_LinkListLen == 0) {
        return NULL;
    }
    LinkList *ret = head;
    while (pos) {
        ret = ret->next;
    }
    return ret;
}

void DelLinkList(LinkList *head)
{
    if (head == NULL) {
        return;
    }
    LinkList *pTemp = head;
    while (pTemp) {
        LinkList *p = pTemp->next;
        free(pTemp);
        pTemp = p;
    }
    g_LinkListLen = 0;
    head          = NULL;
}

int cmp(const void *a, const void *b)
{
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    if (arg1 < arg2) {
        return -1;
    } else if (arg1 > arg2) {
        return 1;
    } else {
        return 0;
    }
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    if (nums[0] <= 0 && nums[numsSize-1] >= 0) {
        LinkList *head = InitLinkList();
        for (int i = 0; i != numsSize; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int l = i + 1;
            int r = numsSize - 1;
            while (l < r) {
                if (nums[l] + nums[r] + nums[i] == 0) {
                    Data tmp = { nums[i], nums[l], nums[r] };
                    head     = InsertElem(head, tmp);
                }
                if (nums[l] + nums[r] + nums[i] <= 0) {
                    while (l < r && nums[l] == nums[++l]) {
                        ;
                    }
                } else {
                    while (l < r && nums[r] == nums[--r]) {
                        ;
                    }
                }
            }
        }
        if (g_LinkListLen == 0) {
            *returnSize        = 0;
            *returnColumnSizes = NULL;
            return NULL;
        }
        int **ret          = (int **)malloc(sizeof(int *) * g_LinkListLen);
        *returnColumnSizes = (int *)malloc(sizeof(int) * g_LinkListLen);
        *returnSize        = 0;
        LinkList *pTemp    = head;
        while (pTemp) {
            ret[*returnSize]                  = (int *)malloc(sizeof(int) * 3);
            ret[*returnSize][0]               = pTemp->data.a;
            ret[*returnSize][1]               = pTemp->data.b;
            ret[*returnSize][2]               = pTemp->data.c;
            (*returnColumnSizes)[*returnSize] = 3;
            (*returnSize)++;
            pTemp = pTemp->next;
        }
        DelLinkList(head);
        return ret;
    } else {
        *returnSize        = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
}
```