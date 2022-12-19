### 解题思路
此处撰写解题思路
思路：
遍历nums2时，拿遍历到的当前元素nums2[i]和nums2[i]之前的元素进行比较，如果存在nums2[i]之前的元素比nums2[i]小，找到该元素在nums1中的下标，并放入输出数组中。
实现：
1、把nums1的每个元素放入哈希表中，供在nums2找到下一个较大值时查找到下标；
2、遍历nums2时，维护一个栈，栈里存放当前还未找到较大值的nums2[i]，
进栈原则：遍历到的当前元素nums2[i]也存在于nums1
出栈原则：当前元素nums2[i]比栈里的元素大，把栈里比nums2[i]小的元素出栈，并找到出栈的数值对应在nums1中的下标，并在输出数组对应位置赋值为nums2[i]。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int idx;
    int value;
} Pair;

typedef struct {
    int n;
    Pair *p;
} HashTable;

void AddToTable(HashTable *t, Pair *p)
{
    int idx = p->value % t->n;
    while (t->p[idx].value != -1) {
        idx = ((idx + 1) % t->n);
    }
    t->p[idx].idx = p->idx;
    t->p[idx].value = p->value;
}

int GetIdx(HashTable *t, int key)
{
    int idx = key % t->n;
    while (t->p[idx].value != key) {
        idx = ((idx + 1) % t->n);
        if (t->p[idx].value == -1) {
            return -1;
        }
    }
    return t->p[idx].idx;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int i;
    HashTable table;
    if (nums1 == 0 || nums1Size == 0) {
        *returnSize = 0;
        return 0;
    }
    int num = (nums1Size > nums2Size ? nums1Size : nums2Size);
    table.n = num;
    table.p = malloc(sizeof(Pair) * num);
    memset(table.p, 0, sizeof(Pair) * num);
    for (i = 0; i < num; i++) {
        table.p[i].value = -1;
        table.p[i].idx = -1;
    }
    int *output = malloc(sizeof(int) * nums1Size);
    for (i = 0; i < nums1Size; i++) {
        output[i] = -1;
    }
    Pair tmp;
    // nums1进行Hash处理，便于根据值查找到对应下标
    for (i = 0; i < nums1Size; i++) {
        tmp.idx = i;
        tmp.value = nums1[i];
        AddToTable(&table, &tmp);
    }
    for (i = 0; i < nums1Size; i++) {
        if (i != GetIdx(&table, nums1[i])) {
            printf("wrong %d[%d %d]\n", nums1[i], i, GetIdx(&table, nums1[i]));
        }
    }

    int *stack = malloc(sizeof(int) * nums1Size);
    int stackLen = 0;

    for (i = 0; i < nums2Size; i++) {
        for (int j = 0; j < stackLen; j++) {
            if (nums2[i] > stack[stackLen - 1 - j]) {
                // 找到了下一个较大值，将对应下标赋值为nums2[i]
                output[GetIdx(&table, stack[stackLen - 1 - j])] = nums2[i];
                stackLen--;
                j--;
            } else {
                break;
            }
        }
        if (GetIdx(&table, nums2[i]) != -1) {
            // 如果当前元素存在于nums1中，入栈，后面要找到比它大的下一个元素
            stack[stackLen++] = nums2[i];
        }
    }
    free(stack);
    free(table.p);
    *returnSize = nums1Size;
    return output;
}
```