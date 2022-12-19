### 解题思路
![image.png](https://pic.leetcode-cn.com/7f5d2d177c4623a2f5414de59d2d2f501cb7e48455a0a2ae41e7c8cd37f9bb2a-image.png)

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return 0;
        ListNode *cur=head;
        ListNode *sential =new ListNode(0);
        sential->next=head;
        ListNode *prev;
        ListNode *tmp;
        bool flag=false;
        while(cur!=NULL&&cur->next!=NULL)
        {
            flag=true;
            tmp=cur;
            if(cur->next->val==cur->val)
            {
                int ans = cur->val;
                prev=cur;
                while(cur->next!=NULL)
                {
                    cur=cur->next;
                    if(cur->val!=ans)break;
                }
                prev->next=cur;
            }
            else
                cur=cur->next;
        }
        if(flag)
        {
            if(tmp->val==tmp->next->val)tmp->next=NULL;
        }
        return sential->next;
    }
};
```