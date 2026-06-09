### 解题思路
O（n）,逐位調整即可

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
        if(head==nullptr) return nullptr;
        ListNode* fol = head->next;
        ListNode* pre=nullptr;
        while(fol!=nullptr){//fol保存了後一個，pre保存了前一個   
            head->next=pre;
            pre=head; //pre後移
            head=fol;//head後移
            fol=fol->next;
        }
        //fol==nulptr,將最後的元素指針接上
        head->next=pre;
        return head;
    }
};
```