### 解题思路
* 先确定head节点，然后迭代两个链，最后有其中一条空，则遍历另一条非空直接加在尾部。
* head固定头节点，h则指向尾。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        if(l1 && l2) {
            if(l1->val < l2->val){
                posHead(l1, head);
            }
            else {
                posHead(l2, head);
            }
        }
        else if(l1) {
            posHead(l1, head);
        }
        else if(l2) {
            posHead(l2, head);
        }

        ListNode *h = head;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                moveP(l1, h);
            }
            else {
                moveP(l2, h);
            }
        }
        while(l1) {
            moveP(l1, h);
        }
        while(l2) {
            moveP(l2, h);
        }
        return head;
    }
    void posHead(ListNode *&l, ListNode *&head) {
        head = l;
        l = l->next;
    }
    void moveP(ListNode *&l, ListNode *&h) {
        h->next = l;
        h = l;
        l = l->next;
    }
};
```
![4.png](https://pic.leetcode-cn.com/dc1fbc8ff6c52c150ec00afc5097ba6c057a38558280bc06d85bb83188932756-4.png)
