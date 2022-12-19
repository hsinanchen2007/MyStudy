各位大佬已经讲得很明白啦，在这里提供C++参考代码
![image.png](https://pic.leetcode-cn.com/5a1521cc2110d7c276860131e95f936bcaa1bb2137350c54babcc463bb855d32-image.png)
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)    return true;
        //f,s是快慢指针.....p,c是反转链表的指针
        ListNode *f = head, *s = head, *p = head, *c = head;
        int flag = 0;
        while(f){
            if(f->next)
                f = f->next->next;
            else{
                f = f->next;
                flag++;
            }
            s = s->next;
            if(c != p && c != s){
                c->next = p;
                p = c;
            }
            if(p == head)
                p->next = NULL;
            c = s;
        }
        if(flag)    p = p->next;
        while(p && s){
            if(p->val != s->val)
                return false;
            p = p->next;
            s = s->next;
        }
        return true;
    }
};
```
