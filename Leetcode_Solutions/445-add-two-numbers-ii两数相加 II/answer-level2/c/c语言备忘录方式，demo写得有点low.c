### 解题思路
备忘录方式

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define max(a, b) a > b ? a : b

int len_func(struct ListNode* list) {
    if (list == NULL)
        return 0;
    struct ListNode* node = list->next;
    int len = 1;
    while(node != NULL) {
        len++;
        node = node->next;
    }

    return len;
}

void padd_func(int *list, int len, struct ListNode* l, int len1) {
    int i = 0;

    if (len > len1) {
        i = len -len1;
    }

    struct ListNode* node = l;
    while(node != NULL) {
        list[i] = node->val;
        i++;
        node = node->next;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int *list1, *list2; 
    int len, i, len1, len2, j = 1, add = 0, sum;
    struct ListNode* ret, *ptail;
    len1 = len_func(l1);
    len2 = len_func(l2);
    len = max(len1, len2);
    ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ptail = ret;
    ptail->next = NULL;
    
    list1 = (int *)malloc(len * sizeof(int));
    memset(list1, 0, len * sizeof(int));
    list2 = (int *)malloc(len * sizeof(int));
    memset(list2, 0, len * sizeof(int));

    padd_func(list1, len, l1, len1);
    padd_func(list2, len, l2, len2);
    
    for(i = len - 1; i >= 0; i--) {
        sum = list1[i] + list2[i] + add;
        if (sum >= 10) {
            list1[i] = sum % 10;
            add = 1;
        } else {
            list1[i] = sum;
            add = 0;
        }

        printf("%d\n", list1[i]);
    }
    if (add) {
        ptail->val = add;
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = list1[0];
        node->next = NULL;
        ptail->next = node;
        ptail = node;
    } else {
        ptail->val = list1[0];
    }

    for (i = 1; i < len; i++) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = list1[i];
        node->next = NULL;
        ptail->next = node;
        ptail = node;
    }
    printf("%d\n", len);

    return ret;
}
```