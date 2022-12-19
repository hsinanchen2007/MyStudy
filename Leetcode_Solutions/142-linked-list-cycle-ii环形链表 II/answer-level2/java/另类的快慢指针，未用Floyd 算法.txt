另一种快慢指针法。

大多数的题解中给出的方法，尤其是官方给的那个解法。自我觉得，在面试中我很难搞定，所以就另辟蹊径，自己重新琢磨出个规律来。

![image.png](https://pic.leetcode-cn.com/d3f9dd3709098e5fc1028a0cb8c38692f1650f616e1f6c772b3dda63cd769448-image.png)

图是从官方的解答中抄来的。
依旧是两个指针，
step1 每次走1步 step2 每次走两步。
相遇的时候。
step1 走了 k步， step2 2k步
方程为: 
(非环的长度) + m * (环的长度) = k
(非环的长度) + n * (环的长度) = 2k
方程是无解的。
这个时候，如果让step1与step2继续走。进行第二次相遇。那么方程为
(非环的长度) + (m + 1) * (环的长度) = k
(非环的长度) + (n + 2) * (环的长度) = 2k

在从第一次相遇到第二次相遇的过程中，对 step1的步数进行count。那么count的值就是(环的长度)了。

然后再让两个指针回到头节点。让一个指针，先走 count步，第二个指针再走。步长都为1。
那么这次两个指针相遇的地方，就是环的初始位置了。
Java代码：
```
public ListNode detectCycle(ListNode head) {
    ListNode stepOne = head;
    ListNode stepTwo = head;
    int count = 0;
    boolean flag = false; // 用来标记是否已经相遇过一次了。
    while(true) {
        if(stepOne == null || stepOne.next == null 
           || stepTwo == null || stepTwo.next == null || stepTwo.next.next ==null) {
            return null;
        }
        stepOne = stepOne.next;
        stepTwo = stepTwo.next.next;
        if(flag){// 第二次相遇
            count++;// 第二次相遇后，开始计算stepOne的步数
            if(stepOne == stepTwo) { // 再次相遇的话，count的值，正好是环的大小。
                break;
            }
        }
        if(stepOne == stepTwo) {
            flag = true;
        }
    }
   stepOne = head;
   stepTwo = head;
    while(count-- > 0) {
        stepOne = stepOne.next; // 先走count步
    }
    while(true) {
        if(stepOne == stepTwo) return stepOne; // stepOne正好多走了环的一圈。（count）步，在环的开始处与stepTwo相遇了
        stepOne = stepOne.next;
        stepTwo = stepTwo.next;
    }
}
```



