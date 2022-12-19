### 解题思路
![image.png](https://pic.leetcode-cn.com/7a8a2fcc3140aabee5d4a77b80e0e4b6736c1ebeb723adba2b6668b7f624e1ef-image.png)
### 代码

```cpp
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        int dif = n - m;
        if(!dif) return head;

        auto p = dummy;
        while(--m) p = p->next; //找到第m-1个点

        auto q = p->next;
        while(dif--) q = q->next;//找到第n-1个点

        auto pre = p->next,cur = pre->next;
        pre->next = q->next;//将第m个点的next指针指向第n个节点的后继节点
        
        //反转从第m个节点到第n个节点之间的next指针
        while(pre != q){
            auto tail = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tail;
        }
        
        p->next = q;//将第m-1个节点的next指针指向第n个节点

        return dummy->next;
    }
};
```