### 解题思路
方法一：快慢指针

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head || k==0)
        {
            return NULL;
        }    
        ListNode *pahead=head;
        ListNode *pbehind=NULL;

        for(unsigned int i=0;i<k;++i)
        {
            if(pahead)
            {
                pahead=pahead->next;
            }
            else
            {
                return NULL;
            }
        }

        pbehind=head;

        while(pahead)
        {
            pahead=pahead->next;
            pbehind=pbehind->next;
        }
        return pbehind;
    }
};
```