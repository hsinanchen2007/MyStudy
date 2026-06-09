### 双指针：
设立快慢两个指针，快指针以步长为２遍历，慢指针以步长为１遍历，若无环，则快指针首先到表尾。若快追上慢，表明有环。

### 代码

```c
bool hasCycle(struct ListNode *head) 
{
    if(!head || !head->next)
        return false;
    struct ListNode *p, *q;
    p = head->next;
    q = head;
    while(p != q)  {
        if(!p || !p->next){
            return false;
        }
        p = p->next->next;
        q = q->next;
    }
    return true;
}
```
### 哈希
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        set<ListNode*> s;
        ListNode *p = head;
        while(p){
            if(s.find(p) != s.end())
                return true;
            s.insert(p);
            p = p->next;
        }
        return false;
    }
};
```