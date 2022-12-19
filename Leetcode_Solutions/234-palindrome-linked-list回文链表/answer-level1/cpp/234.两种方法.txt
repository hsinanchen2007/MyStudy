```
class Solution {
public:
    //方法二快慢指针
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        ListNode* low=head;
        ListNode* fast=head;
        ListNode* pre=head;
        ListNode* prepre=NULL;
        while(fast!=NULL&&fast->next!=NULL){
            pre = low;
            low=low->next;
            fast=fast->next->next;
            pre->next = prepre;
            prepre = pre;
        }
        if(fast!=NULL) low=low->next;
        while(low!=NULL){
            if(pre->val!=low->val) return false;
            pre=pre->next;
            low=low->next;
        }
        return true;
    }
    // 方法一
    // bool isPalindrome(ListNode* head) {
    //     vector<int> vec;
    //     while(head!=NULL){
    //         vec.emplace_back(head->val);
    //         head=head->next;
    //     }
    //     for(int i=0,j=vec.size()-1;i<j;i++,j--){
    //         if(vec[i]!=vec[j]) return false;
    //     }
    //     return true;
    // }
};
```
