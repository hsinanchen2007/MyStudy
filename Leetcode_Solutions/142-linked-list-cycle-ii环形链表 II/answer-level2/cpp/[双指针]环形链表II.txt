1. 先判断有无环（用快慢指针法）
2. 发现有环后，从头和交汇点分别开始每次往前移动一个，当再次交汇时，其便为环的入口。

```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* h1 = head;
        ListNode* h2 = head;
        while(h1 != NULL && h2 != NULL && h1->next != NULL && h2->next != NULL) {
            h1 = h1->next->next;
            h2 = h2->next;
            // 链表有环
            // 从链表头再开始一个遍历，每次头和当前的交汇点(h1)都往前移动一个
            // 当头等于h1时，代表相遇，此时其为环的入口。
            if(h1 == h2) {
                ListNode* hh = head;
                while(head != h1) {
                    head = head->next;
                    h1 = h1->next;
                }
                return head;
            }
        }
        return NULL;
    }
};
```


**具体理论见官方题解：**

[无效的图片地址](https://picturesbed.oss-cn-hangzhou.aliyuncs.com/img/20190617194006.png)
