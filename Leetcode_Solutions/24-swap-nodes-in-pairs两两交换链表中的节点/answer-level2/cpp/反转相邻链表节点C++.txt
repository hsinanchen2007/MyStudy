### 解题思路
![leetcode24swapnodeinparis.JPG](https://pic.leetcode-cn.com/763b502bd7d33405e1f24473b509a4441fa24f5d074f2b0f2649b5842bce6712-leetcode24swapnodeinparis.JPG)

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
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummHead = new ListNode(0);
        dummHead->next = head;

        ListNode *p = dummHead;
        while(p->next && p->next->next){
            ListNode * node1 = p->next;
            ListNode * node2 = node1->next;
            ListNode * next = node2->next;

            node2->next = node1;
            node1->next = next;
            p->next = node2;
            
            p = node1;
        }

        ListNode *retNode = dummHead->next;
        delete dummHead;

        return retNode;
    }
};
```