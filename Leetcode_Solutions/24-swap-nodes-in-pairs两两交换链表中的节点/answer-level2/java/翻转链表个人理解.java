### 解题思路
解法参考官方教程,然后把自己理解的翻译成注释代入到执行步骤里面
    /**
    *1  变量 > 右边表示next节点
    *2  第1次进来方法 函数最外层 开始 f=1>2>3>4>5,s=2>3>4>5>null;  f.next=?  (第5行的结果)
    *3  第1次递归进入该函数参数head=s.next   即  3>4>5,     f=3>4>5,s=4>5；   f.next=? (第4行结果)
    *4 第2次递归进入该函数参数head=s.next 即  5>null      return  5>null
    *5 满足条件停止递归 返回5>null,代入到注释第3行的?里面   即  f=3>5>null; s.next=f;  return 4>3>5>null;
    *6  第1次进来方法 函数最外层 结束    f=1>4>3>5>null; s.next=f;  return 2>1>4>3>5;
    */
### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        //如过当前节点或next指向的节点为null,满足条件,退出递归,凡是递归调用,必定会有终止条件
        if ((head == null) || (head.next == null)) {
            return head;
        }
        ListNode f = head;
        ListNode s = head.next;
        // Swapping
        f.next  = swapPairs(s.next);
        s.next = f;
        return s;
    }
}
```