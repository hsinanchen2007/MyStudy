+ 设置一个前驱节点，即可
+ 改进点：如果能不new，那么速度会更快
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if(!head) return nullptr;

        ListNode* pre  = new ListNode(0);
        pre->next = head;
        ListNode* ret = pre;
        
        //只是需要改变那些重复的指向，没有重复的就不需要改变指针指向
        while(head){

            while(head->next && head->val == head->next->val) head = head->next;
            if(pre->next != head) pre->next = head->next;
            else pre = pre->next;
           
            head = head->next;
        }
        return ret->next;
    }
    
};
```
