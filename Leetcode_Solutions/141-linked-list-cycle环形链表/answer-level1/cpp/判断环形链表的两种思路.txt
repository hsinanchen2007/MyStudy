环形链表的判断我这里总结两种思路：一个是用关联容器set来实现，一个是用快慢双指针来实现。
利用set实现：
   用指针p遍历链表。p为空则说明无环，结束循环，返回false；不为空，则判断p是否在p_set中，如果在集合内，则说明存在环，返回true，否则将p插入集合内。
```
    bool hasCycle(ListNode *head) {
        set< ListNode *>p_set;
        ListNode *p=head;
        while(p){
            if(p_set.find(p)!=p_set.end())
                return true;
            p_set.insert(p);
            p=p->next;
        }
        return false;
    }
```
运行结果：56ms，11.9MB

利用快慢双指针实现：
    这个原理大家想必都比较清楚，就不再啰嗦了。只说我这里快指针每步移动两个节点，慢指针每次移动一个节点。
```
    bool hasCycle(ListNode *head) {
        set< ListNode *>p_set;
        ListNode *p=head;
        while(p){
            if(p_set.find(p)!=p_set.end())
                return true;
            p_set.insert(p);
            p=p->next;
        }
        return false;
    }
```
运行结果：16ms,9.8MB  

