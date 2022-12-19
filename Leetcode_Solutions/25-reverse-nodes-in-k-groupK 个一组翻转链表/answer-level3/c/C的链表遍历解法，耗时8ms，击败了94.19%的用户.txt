### 解题思路
1. 遍历整个链表，每k个元素，记录这K个元素的first和last的位置
2. 然后将这K个元素翻转，并将这K个元素的`first->next = NULL;`
3. 记录这K个元素的first(反转后将会是最后一个)置为prev
4. 然后进行重复步骤1,2,3，并将上一次的`prev->next = last;`,
5. 对于多余部分，直接将`prev->next = first;`

时间复杂度为：O(n),
空间复杂度为：O(1)

有些同学提出，边遍历边反转，我个人不太赞同，虽然循环次数变少了一点，但本质上并没有提升，反而代码写的不易懂，可维护性就体现出来了。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head, struct ListNode* tail) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = head;

    if (NULL == head) {
        return NULL;
    }

    while (prev != tail && NULL != current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return tail;
} 


struct ListNode* reverseKGroup(struct ListNode* head, int k){

    struct ListNode* first = head;
    struct ListNode* last= head;
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = head;
    struct ListNode* newHead = head;
    int i = 0;

    while (NULL !=  current) {
        i++;
        next = current->next;
        if (0 == i%k) {
            last = current;
            reverse(first,last);
            if (i == k) {
                newHead = last;
            }
            if (NULL != prev) {
                prev->next = last;
            }
            prev = first;
            first = next;
        }
        current = next;
    }

    if (0 != i%k && NULL != prev ) {
        prev->next = first;
    }

    return newHead;
}
```