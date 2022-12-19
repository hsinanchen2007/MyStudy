### 解题思路
既然题目说了要实际交换节点，也就是不创建新的节点，直接修改指针。那么算栈、双端队列啥的也就不考虑了。
**1. 双指针找中间节点，注意有个坑**
***坑就是，前半部分的末尾要断开。因为最终前半部分的末尾可能是作为整个结果链表的末尾，不断开，OJ会出现各种错误***
**2. 将后半部分原地反转**
这个不用多说，lc有原题
**3. 依次取后半部分的每一个节点，交叉插入前半部分**

### 代码

```cpp
class Solution {
public:
    void reorderList(ListNode* head) {
        if ( !head || !head -> next ) {
            return;
        }
        ListNode *fast = head, *slow = head;
        while ( fast -> next && fast -> next -> next ) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        fast = slow -> next;                    // slow -> next 是后半部分的开始
        slow -> next = nullptr;                 // 操，记得把前半部分的末尾断掉（置空）。。。。不然后面会有问题。。。

        // 原地反转
        ListNode *pre = nullptr, *tmp = nullptr;       // 遍历过程中，直接修改next指针
        while ( fast ) {
            tmp = fast -> next;                 // 先把当前节点的下一个保存下来
            fast -> next = pre;                 // 当前节点的next修改，指向它的前一个节点
            pre = fast;                         // pre 指针往后走
            fast = tmp;                         // head工作指针走一步 ===> 工作指针始终再pre前面
        }

        // 合并
        ListNode *p1 = head, *p2 = pre, *temp = nullptr;        // pre 是后半部分反转后的第一个节点
        while ( p2 ) {
            temp = p2 -> next;
            p2 -> next = p1 -> next;
            p1-> next = p2;
            p1 = p2 -> next;
            p2 = temp;
        }
    }
};
```