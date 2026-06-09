### 解题思路
* 先遍历一遍读出链表长度，然后删除第n个。
* 删除时有两种情况：要删除节点（1）是第一个节点；（2）不是第一个节点。
* 第一种情况，直接修改head=head->next;
* 第二种情况，可以使用[237. 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/solution/237-shan-chu-lian-biao-zhong-de-jie-dian-by-user42/)的方法删除。

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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = head;
        int len = 0;
        for(; tmp; len++)
            tmp = tmp->next;
        
        if(n == len) {
            ListNode *t = head;
            head = head->next;
            delete t;
            return head;
        }

        tmp = head;
        for(int i=1; i < len - n; i++) {
            tmp = tmp->next;
        }
        ListNode *t = tmp->next;
        tmp->next = t->next;
        delete t;
        return head;
    }

};
```
![2.png](https://pic.leetcode-cn.com/b44efcaaf34302899edb177269934688425c6ebd5815c16da57a6a5a5feaa17d-2.png)
