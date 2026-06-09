```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return true;
        int count = 1;
        ListNode* current = head;
//      顺序遍历一次，记录长度，再遍历第二次找到中点，替换成后面的双指针       
//         while(current->next){
//             current = current->next;
//             count ++;
//         }
        
//         current = head;
//         int steps = count /2-1;
//         if(count%2)steps += 1;
//         for(int i=0;i<steps;i++){
//             current = current->next;
//         }
        
        //找中点改成双指针遍历可以少遍历一半长的List
        ListNode* fast = head;
        while(fast->next){
            fast = fast->next;
            count ++;
            if(fast->next==nullptr)break;
            current = current->next;
            fast = fast->next;
            count ++;
        }
        
        ListNode* second_half = current->next;
        current->next = nullptr;
        ListNode* first_half = reverse(head);
        //若结点数为奇数，前半段先走一步对齐
        if(count%2 == 1)first_half = first_half->next;
        while(first_half != nullptr){
            if(first_half->val != second_half->val)return false;
            else{
                first_half = first_half->next;
                second_half = second_half->next;
            } 
        }
        return true;
        
        
    }
    //迭代实现List反转，#206题
    ListNode* reverse(ListNode* head){
        if(head->next==nullptr)return head;
        ListNode* previous = head;
        ListNode* current = head->next;
        while(current){
            ListNode* n = current->next;
            current->next = previous;
            previous = current;
            current = n;
        }
        head->next = nullptr;
        return previous;
    }
};
```
