只需要一次遍历，将链表中的节点的地址存储起来，根据栈结构先进后出的特性，可以很方便地得到倒数第n个节点的地址；接下来只需要判断栈是否为空，即可判断删除的是不是头节点，如果是头节点被删除，则单独处理；若不是头节点被删除，则此时再读出栈顶元素，即待删除节点的前一个节点的地址，之后也可以很容易完成对某一个节点删除的工作。代码如下：
```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> s;
        ListNode* cur=head;
        while(cur!=NULL){
            s.push(cur);
            cur = cur->next;
        }
        for(int i=0; i<n; i++){
            cur = s.top();
            s.pop();    
        }
        if(s.empty()) {
            head = head->next;
            delete cur;
        }else{
            cur = s.top();
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        return head;
    }
};
```
