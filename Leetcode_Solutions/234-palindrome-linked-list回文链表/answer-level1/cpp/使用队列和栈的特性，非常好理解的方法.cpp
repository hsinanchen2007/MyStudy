1.先将链表遍历一遍，分别将每个元素记录到一个栈s和一个队列q中
2.将s和q分别pop()，比较两个pop出的元素大小是否相等，如果不相等，则返回false
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        queue<int> q;
        while(head!=NULL){
            s.push(head->val);
            q.push(head->val);
            head=head->next;
        }
        while(!s.empty()&&!q.empty()){
            int v1=s.top();     s.pop();
            int v2=q.front();   q.pop();
            if(v1!=v2) return false;
        }
        return true;
    }
};
```
