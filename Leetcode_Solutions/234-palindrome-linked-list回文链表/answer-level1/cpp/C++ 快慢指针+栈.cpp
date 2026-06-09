```
        //     s-慢指针 f-快指针
        //     循环结束时的状态如下:
        //     1 2 2 1 NULL   偶数长度 后半部分起点就是s
        //         s    f
        //     1 2 3 2 1 NULL 奇数长度  后半部分起点是s的下一个
        //         s   f
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;//0个或1个数自然为真
        stack<int> stk;//存放前半个数
        auto f = head,s = head;
        while(f&&f->next){
            stk.push(s->val);
            s = s->next;
            f = f->next->next;
        }
        if(f) s = s->next;//后半部分起点
        while(s){
            if(s->val!=stk.top()) return false;
            stk.pop(),s = s->next;
        }
        return true;
    }
```
