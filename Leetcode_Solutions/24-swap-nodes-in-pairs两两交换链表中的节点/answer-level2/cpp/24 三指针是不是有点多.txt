### 解题思路
用了三个指针，如果算上哑节点都四个了。。。
指针少了逻辑容易混乱。
指针p指示交换的两个结点中的前一个，指针q指示交换的两个结点中的后一个，指针r指示p指示结点的前一个节点。
### 代码

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return head;
        ListNode *dummy = new ListNode(-1); //设置哑节点
        dummy->next = head;
        ListNode *p = head;
        ListNode *q = p->next;
        ListNode *r = dummy;
        while (p && q) {
            //更新链接关系
            r->next = q;
            p->next = q->next;
            q->next = p; 
            //指针递增
            r=p;
            p = p->next;           
            if (!p)
                break;           
            q = p->next;
            if (!q)
                break;
        }
        return dummy->next;
    }
};
```