### 解题思路
这一题最简单的思路，就是循环一遍，查询到链表的元素个数X，然后再迭代X-k次就可以找到倒数第k个节点。

另一个思路就是，先使用指针cur指向第一个节点，然后使用nextK指针指向第k+1个节点，利用双指针同时move，当nextK位空的时候，cur这时候已经指向了倒数第k个节点。

### 边界条件
1. nextK要指向第k+1个节点，这样才能保证，当nextK位空的时候，cur为指向倒数第k个节点
2. 当k为0或是k为超过链表大小的数时，会出现错误，此时要返回-1（当然，这一题已经保证了k的有效性，可以不考虑）

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        if (k <= 0) {
            return -1;
        }
        int ret = -1;
        // get the k val, if the len of the head if less than k, return -1
        ListNode *cur = head;
        ListNode *nextK = head;
        int i = 0;
        while (nextK != NULL && i < k) {
            nextK = nextK->next;
            i++;
        }
        // if the nextK == NULL, return -1
        if (i != k) {
            return ret;
        }

        // move the cur and nextK until the nextK == NULL
        while (nextK != NULL) {
            cur = cur->next;
            nextK = nextK->next;
        }

        ret = cur->val;

        return ret;
    }
};
```