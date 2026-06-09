
递归
```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k < 2)
            return head;
        ListNode* temp = head;
        int i;
        for(i = 1;i <= k;i++){          //找k个一组
            if(temp->next)
                temp = temp->next;
            else    break;
        }
        if(i != k){                    //不足一组
            return head;
        }
        ListNode* next_khead = temp->next;
        temp->next = NULL;
        ListNode* reverse_head = reverse(head);   //逆转当前这一组
        ListNode* next_reverse_head = reverseKGroup(next_khead,k);  //把之后的节点K个一组逆转
        head->next = next_reverse_head;         //把两部分连接起来
                
        return reverse_head;
        
    }
    
    ListNode* reverse(ListNode* head){
        if(!head)
            return head;
        ListNode* pre = NULL;
        ListNode* reverse_head = NULL;
        while(head){
            ListNode* next = head->next;
            if(!next)
                 reverse_head = head;
            head->next = pre;
            pre = head;
            head = next;
        }
        return reverse_head;
    }
};
```
