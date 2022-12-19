```
bool hasCycle(ListNode *head) {//30秒写完的做法..
        int n = 1e4;
        while(n--){
            if(head) head = head->next;
            else return false;
        }
        return true;
    }
    
    bool hasCycle(ListNode *h) {//标答 快慢指针
        auto f = h,s = h;
        while(f&&f->next){//快的还能跑
            s = s->next;
            f = f->next->next;
            if(s==f) return true;//在一个环上，跑得快的和跑得慢的在某一时刻一定会相遇
        }
        return false;
    }
```
