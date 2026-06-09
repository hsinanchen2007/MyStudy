### 解题思路
  借助官方题解理解递归
  对于递归，可以用栈的思想过一遍程序。比如`1->2->3->4->null`,从结点4开始逐个出栈(也可以说是从null开始，不过此时递归结束)。
  对于结点4，显然`4->null`
  对于结点3，`head->next->next = head;`说明`4->3`;`head->next = NULL;`说明`4->3->null`
  对于结点2，`head->next->next = head;`说明`4->3->2`;`head->next = NULL;`说明`4->3->2->null`
  对于结点1，`head->next->next = head;`说明`4->3->2->1`;`head->next = NULL;`说明`4->3->2->1->null`

  对于`head->next->next = head;`，作用就是反转链表
  对于`head->next = NULL;`，作用就是防止形成环。比如，对于结点3，如果没有这步，就变成了`3->4->3`

  tips:对于递归，要么自己打断点过一遍，要么看题解里的大佬的动画演示，相当精彩！

### 迭代

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;           //指向当前结点
        ListNode* pre = NULL;           //指向当前结点的前一个结点

        while(cur){
            ListNode* nex = cur->next;  //指向当前结点的下一个结点
            //反转
            cur->next = pre;
            //更新
            pre = cur;
            cur = nex;
        }

        return pre;
    }
};
```
### 递归

```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return p;
    }
};
```
