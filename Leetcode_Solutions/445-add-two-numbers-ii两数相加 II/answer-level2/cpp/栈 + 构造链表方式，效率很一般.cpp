```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        //先就都放进栈
        std::stack<int> st1;
        std::stack<int> st2;
        ListNode *cur1 = l1,*cur2 = l2;
        while(cur1 || cur2){
            if(cur1){
                st1.push(cur1->val);
                cur1 = cur1->next;
            }
            if(cur2){
                st2.push(cur2->val);
                cur2 = cur2->next;  
            }
        }
        ListNode *head = nullptr,*cur = nullptr;
        int carry = 0;//进位标识
        while(1){
            int tmp1 = 0,tmp2 = 0;
            if(st1.empty() && st2.empty()) break;
            if(!st1.empty()){tmp1 = st1.top();st1.pop();}
            if(!st2.empty()){tmp2 = st2.top();st2.pop();}
            
            cur = new ListNode{tmp1 + tmp2 + carry};
            carry = cur->val/10;
            cur->val %= 10;
            cur->next = head;
            head = cur;
        }
        if(carry){//不能忘记处理最开始一个是否进位
            cur = new ListNode{1};
            cur->next = head;
            head = cur;
        }
        return head;
    }
};
```
