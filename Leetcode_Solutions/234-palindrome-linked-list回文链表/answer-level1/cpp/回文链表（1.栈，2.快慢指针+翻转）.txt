**1.用快慢指针遍历的同时翻转前半部分，然后与后半部分比较即可。**
```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return 1;
        ListNode *fast = head, *slow = head;
        ListNode *p, *pre = NULL;
        while(fast && fast->next){
            p = slow;
            slow = slow->next;    //快慢遍历
            fast = fast->next->next;

            p->next = pre;  //翻转
            pre = p;
        }
        if(fast)  //奇数个节点时跳过中间节点
            slow = slow->next;

        while(p){       //前半部分和后半部分比较
            if(p->val != slow->val)
                return 0;
            p = p->next;
            slow = slow->next;
        }
        return 1;
    }
};
```
**2.将所有节点值入栈，然后一一出栈并比较。**
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *p = head;
        while(p){
            s.push(p->val);
            p = p->next;
        }
        p = head;
        while(p){
            if(p->val != s.top()){
                return 0;
            }
            s.pop();
            p = p->next;
        }
        return 1;
    }
};
```
