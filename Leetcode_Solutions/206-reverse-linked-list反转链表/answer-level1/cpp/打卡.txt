### 解题思路
此处撰写解题思路
![A36B74ED53D2A2B363A6B70BACBDD242.png](https://pic.leetcode-cn.com/9f4a7a45ceb949dcbdf99bf4fbfa8e7caf98e2d7343fdb055e0e4d45cab75521-A36B74ED53D2A2B363A6B70BACBDD242.png)


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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        if(p==NULL ||p->next==NULL){
            return p;
        }
        ListNode* q = p->next;
        ListNode* r = q->next;
        p->next = NULL;
        while(r!=NULL){
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        return q;
        
    }
};
```