作为C/C++程序员，总能在指针操作中获得一种独特的快感。

各位读者，看完下面的程序，你快感了么？


```
class Solution {
public:
    ListNode ** merge(ListNode **res_head, ListNode *l, ListNode *r) {
        auto resp = res_head;
        
        while (l && r) {
            if (l->val < r->val) {
                *resp = l;
                l = l->next;
            } else {
                *resp = r;
                r = r->next;
            }
            resp = &(*resp)->next;
        }
        
        for (*resp = l? l: r; (*resp); resp = &(*resp)->next)
            ;;;

        return resp;
    }
    
    ListNode* sortList(ListNode* head) {
        for (int stride = 1; true; stride *= 2) {
            ListNode **l = &head, *r = nullptr;
            for (auto p = &head; *p; ) {
                l = p;         
                for (int i = 0; i < stride; i++) {
                    p = &(*p)->next;
                    if ((*p) == nullptr)
                        break;
                }
                
                r = (*p);
                if (r == nullptr)
                    break;
                
                auto left_tail = p;
                for (int i = 0; i < stride; i++) {
                    p = &(*p)->next;
                    if ((*p) == nullptr)
                        break;
                }

                *left_tail = nullptr;
                auto tmp = (*p);
                *p = nullptr;
                p = merge(l, *l, r);
                *p = tmp;
            }
            if (*l == head && r == nullptr)
                break;
        }
        return head;
    }
};
```

![image.png](https://pic.leetcode-cn.com/19139994087d4e2797af60cba3f69f69634bbaee317adddfecf1aef26e05eeca-image.png)
