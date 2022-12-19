### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/e4e0ba252c176fcd94de9602e9c2bfb542edbab4c5936bf28cb9fc45653fac3b-image.png)

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
        ListNode*p1=l1,*p2=l2;
        ListNode* res=new ListNode(0),*q;q=res;
        while(p1&&p2)
        {
            if(p1->val<=p2->val)
            {
                q->next=p1;
                p1=p1->next;
            }
            else
            {
                q->next=p2;
                p2=p2->next;
            }
            q=q->next;
        }
        if(p1) q->next=p1;
        if(p2) q->next=p2;
        return res->next;
    }
};
```