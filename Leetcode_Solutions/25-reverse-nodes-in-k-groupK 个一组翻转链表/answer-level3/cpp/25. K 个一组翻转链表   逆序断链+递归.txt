### 解题思路
1-2-3-4-5-6
==3-2-1-反转（4-5-6）
head->next=reverseKGroup(cur,k);

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
    ListNode* reverseKGroup(ListNode* head, int k) {
            auto node=head;
            int i=0;
            while(node){
                i++;
                node=node->next;
            }
            if(i<k) return head;
            //逆序，cur是下一个的头结点，pre是本次的尾结点，head是原头结点，现尾结点
            ListNode* pre=NULL;
            ListNode* cur=head;
            for(int j=0;j<k;j++){
                ListNode* t=cur->next;
                cur->next=pre;
                pre=cur;
                cur=t;
            }
            head->next=reverseKGroup(cur,k);
            return pre;
    }
};
```