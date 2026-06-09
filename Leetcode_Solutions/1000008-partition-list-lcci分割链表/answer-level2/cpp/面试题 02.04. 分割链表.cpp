### 解题思路
情况一：
交换节点
情况二：
交换节点中的元素

### 代码
情况一：
```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL) return head;
        int cnt=0;
        ListNode* h=new ListNode(0);
        ListNode* slow=new ListNode(0);
        slow->next=head;
        ListNode* fast=head;
        ListNode* pre=head;
        h=slow;
        pre=slow;
        while(fast){
            if(fast->val<x){//小于x的节点，要接在slow后面
                if(fast==slow->next){
                    slow=slow->next;
                    pre=pre->next;
                    fast=fast->next;
                }else{
                ListNode* fnex=fast->next;
                ListNode* snex=slow->next;
                slow->next=fast;
                slow=slow->next;
                slow->next=snex;
                pre->next=fnex;
                fast=fnex;
                }
            }else{//值大于等于x，无需理会
                pre=pre->next;
                fast=fast->next;
            }
        }
        return h->next;
    }
};
```

情况二：
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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL) return head;

        ListNode* fast=head;
        ListNode* pre=head;
        
        while(fast){
            if(fast->val<x){
                int tmp=pre->val;
                pre->val=fast->val;
                fast->val=tmp;
                pre=pre->next;
            }
            fast=fast->next;
        }
        return head;
    }
};
```