
```c++
   bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        if(head->next == nullptr) return true;
        
        stack<int> s;
        ListNode* slow;
        ListNode* fast;
        int flag = 0;
        
        // 使用快慢指针遍历前半部分的链表, 并使用stack保存值
        slow = fast = head;
        while(fast){
            s.push(slow->val);
            slow = slow->next;
            if(fast->next != nullptr)
                fast = fast->next->next;
            else{
                fast = nullptr;
                flag = 1;
            }     
        }
        
        // 判断如果链表是奇数个, 就删除栈顶保存的链表中间的值
        if(flag){
            s.pop();
        }
        
        // 遍历后半部分的值,并与stack栈顶的值做比较, 不同则不是回文链表
        while(slow){
            if(slow->val != s.top()){
                return false;
            }
            s.pop();
            slow = slow->next;
        }
        return true;
    }
```
