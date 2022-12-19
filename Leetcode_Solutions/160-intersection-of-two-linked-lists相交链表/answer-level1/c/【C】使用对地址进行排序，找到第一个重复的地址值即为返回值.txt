1.构造数组
2.初始化所有地址值
3.排序
4.遍历求重复的点即为返回值
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int listNodePointerCompareFunc(const void *left, const void *right) 
{
    const struct ListNode **l = left;
    const struct ListNode **r= right;
    return (*l) - (*r);
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    
    int count1 = 0;
    struct ListNode *node = headA;
    while (node) {
        count1++;
        node = node->next;
    }
    
    int count2 = 0;
    node = headB;
    while (node) {
        count2++;
        node = node->next;
    }
    
    int totalSize = count1 + count2;
    struct ListNode **data = (struct ListNode **) malloc(sizeof(struct ListNode *) * totalSize);
    if (data == NULL) {
        return NULL;
    }
    memset(data, 0, sizeof(struct ListNode *) * totalSize);
    
    int index = 0;
    node = headA;
    while (node) {
        data[index++] = node;
        node = node->next;
    }
    node = headB;
    while (node) {
        data[index++] = node;
        node = node->next;
    }
    qsort(data, totalSize, sizeof(struct ListNode *), listNodePointerCompareFunc);
    
    struct ListNode *start = data[0];
    for (int i = 1; i < totalSize; ++i) {
        if (start == data[i]) {
            free(data);
            data = NULL;
            return start;
        } else {
            start = data[i];
        }
    }
    free(data);
    data = NULL;
    return NULL;
}
```
