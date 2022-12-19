1. 先把链表变成环，
2. 把旋转变成前移动
3. 移动结束，再打开环
时间复杂度O(n),空间复杂度O(1)

```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //先把链表变成环，然后旋转，结束后再打开
        if(!head) return nullptr;
        ListNode* cur = head;
        ListNode* end = nullptr;
        int len = 1;
        while(cur->next){cur=cur->next; len ++;}
        cur->next = head;   //变成一个环
        end = cur;          //记录末尾
        int offsets = len - k%len;
        while(offsets--) {head = head->next; end=end->next;}
        
        end->next = nullptr;
        return head;
    }
};
```

