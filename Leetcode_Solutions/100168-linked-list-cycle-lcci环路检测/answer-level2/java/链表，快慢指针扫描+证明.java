
来自 B站 大雪菜 的题解 ，贴了链接会屏蔽

我是个搬运工的

有俩个指针 fast ,slow分别的从起点a 开始走，slow走一步，fast走里俩步。如果过程中 快fast走到null,说明不存在环。否则fast和slow一定会相遇，相遇后，slow待在原地不动，将 fast放回原点。然后俩个指针每次都走一步，每次都走一步，每次都走一步。当俩个指针相遇的时候，就是环的入口。


![1_54311a0411-QQ图片20180531162503.png](https://pic.leetcode-cn.com/b9706c0acddf302d43ad3b6cf424a9e9d42031e6c51356722ca95bccb37be486-1_54311a0411-QQ%E5%9B%BE%E7%89%8720180531162503.png)

证明：如上图所示，a是起点，b是环的入口，c是俩个指针相遇点，ab之间距离为x，bc之间距离是 y。

当slow 走到 b 时，由于fast 比 slow 走的快，所以fast 已经从 b 开始在环上走了 x 步，可能是多余一圈，距离 b 还差 y 步(解释：我们知道俩个指针相遇的点在c，我们让 slow 退回到b，fast 则会退回 2y 步，所以就是距离b 还差y 步，不会可以画图模拟一下)。知道了 fast 距离 b 还差 y 步，上面知道了 fast 从 b 开始在环上走了 x步。所以环的长度为 x+y。所以当俩个指针相遇时，把 fast 放回原点，slow 在 c点不动。然后每次都走一步，下一次相遇的时候就是b 点环的入口。

还有一种证明方法比较抽象，去大雪菜的网站可以自行查看

```java
    public ListNode detectCycle(ListNode head) {
        if(head==null||head.next==null){
            return null;
        }
        ListNode fast=head;
        ListNode slow=head;
        while (fast!=null&&slow!=null){

            fast=fast.next;
            slow=slow.next;
            if(fast!=null)
                fast=fast.next;
            else
                return null;
            if(fast==slow){//如果相遇了，从头开始
                slow=head;
                while (fast!=slow){
                    fast=fast.next;
                    slow=slow.next;
                }
                return slow;
            }
        }
        return null;
    }
```


```C++
class Solution {
public:
    ListNode *entryNodeOfLoop(ListNode *head) {
        if (!head || !head->next) return 0;
        ListNode *first = head, *second = head;

        while (first && second)
        {
            first = first->next;
            second = second->next;
            if (second) second = second->next;
            else return 0;

            if (first == second)
            {
                first = head;
                while (first != second)
                {
                    first = first->next;
                    second = second->next;
                }
                return first;
            }
        }

        return 0;
    }
};
```

