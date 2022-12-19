### 解题思路
找到res的首段，后与head连接，变成循环链表。然后断开
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* node = head;
        int l = 0;
        if(!head) return head;
        while(node->next)
        {
            node=node->next;
            l++;
        }
        k =k%(l+1);
        if (!k) return head;
        node ->next =head;
        ListNode *res = head;
        for(int i = l-k;i>=0;i--)
            res=res->next;
            cout<<res->val;
        ListNode *h = head;
        while(1)
        {
            if(h->next==res)
                break;
            else
                h=h->next;
        }
        h->next =NULL;
        return res;
    }
};
```