本题应该是经典入门的链表题，但是菜鸟如我，看到这个题，完全忘了要用快慢指针的办法。
大概想了想，觉得可以通过反转链表来解决。提交通过后，发现题解里似乎没看到有人用这种方法，所以也补充在这里，仅供参考。

核心思想很简单，当遍历链表时，顺带把链表反转，那么如果有环，则最后必然停在原始链表的head节点上。
注意上面的一个例外就是当链表只有一个节点时，也会停在head上，而此时并没有环。所以还需针对此特殊情况做下判断。

代码如下：
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (nullptr == head ) return false;
        ListNode * pre = nullptr;
        ListNode * cur = head;
        ListNode * tmp = nullptr;
        int node_count = 0;
        while (nullptr != cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
            ++node_count;
        }
        return node_count == 1 ? false : pre == head;
    }
};
```
这种解法的一个缺点是，会改变原始链表。
