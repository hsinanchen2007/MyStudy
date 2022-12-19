### 思路
- 常规做法，取`odd`指针指向第一个节点，`even`指针指向第二个节点（实现代码的时候用不到`odd`指针，这里写出来只是帮助理解）
- 用指针`oddtemp` 和`eventemp` 来分离奇偶链表
- 分离结束后将`odd`段链表的尾指针指向`even`链表的`head`。

![奇偶t.png](https://pic.leetcode-cn.com/482e4e6f419006e09e30a119a56a600cc0f073bc2c0ecc8ed2d4a7dc6a528c6f-%E5%A5%87%E5%81%B6t.png)
```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)   return nullptr;
        ListNode* even = head -> next;
        ListNode* oddtemp = head;
        ListNode* eventemp = even;
        while(oddtemp && eventemp && eventemp -> next){
            oddtemp -> next = eventemp -> next;
            oddtemp = oddtemp -> next;
            eventemp -> next = oddtemp -> next;
            eventemp = eventemp -> next;
        }
        if(!eventemp){
            oddtemp -> next = even;
        }
        else{
            eventemp -> next = nullptr;
            oddtemp -> next = even;
        }
        return head;
    }
};
```