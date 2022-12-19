把链表的值存入栈中，num为个数，然后循环num/2次，判断链表的值是否与栈的top相等。速度击败99.3%
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        stack<int>a;
        auto *p=head;
        int num=0;
        while (p)
        {
            a.push(p->val);
            num++;
            p=p->next;
        }
        p=head;
        for(int i=0;i<num/2;i++)
        {
            if(p->val!=a.top())
            return false;
            p=p->next;
            a.pop();
        }
        return true;
    }
};
```
