
我用的是最普通的双指针法：指针A和指针B一开始同时指在head的位置，然后A走1步的同时B走2步，若B的下一个为空则链表肯定无环，结束；若A和B最终遇见了，则必定存在环。
且因为此时B比A多走的路程就是A已经走过的路程（B的速度是A的2倍，则路程也是A的2倍），故我们还能知道，在“环上”的节点共有A走过的节点那么多个。由此，可以知道pos = 链表的总长度-A走过的节点数。
java代码如下（供参考）：
```
public boolean hasCycle(ListNode head) {
        boolean ans = false;
        if(head != null){
            ListNode first = head; //走一步
            ListNode second = head; //走两步
            while(second.next != null){
                first = first.next;
                second = second.next;
                if(second.next == null)
                    break;
                second = second.next;
                if(first == second){
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }
```

![批注 2020-01-31 100839.png](https://pic.leetcode-cn.com/50c37ac5056711202d8e599d3afbd61687dba67460755ac9ea447f825d6b4dbf-%E6%89%B9%E6%B3%A8%202020-01-31%20100839.png)
