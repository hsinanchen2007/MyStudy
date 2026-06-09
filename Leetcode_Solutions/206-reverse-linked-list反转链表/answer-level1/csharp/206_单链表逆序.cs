### 解题思路

#### 递归思想，逐级回朔

     1----->2----->3----->4----->5----->null

运行过程
head(1)<---head.next(2)
head(2)<---head.next(3)
head(3)<---head.next(4)
head(4)<----head.next(5)
head(5).next==null return


理解的关键在于

1、递归节点head->next反向指回head节点
head->next->next = head
2、去掉之前的链接
head->next = null


#### 循环思路

使用2个额外变量 pre，next
每次循环把当前head的next存下来，然后把head指向pre。
再把pre变成当前的head,head变成当前的next

![image.png](https://pic.leetcode-cn.com/5caefafc3c1170f8b5b4a27bbaed723fa89643aa6092a723dbcfba6ba111f41a-image.png)
![image.png](https://pic.leetcode-cn.com/bf6e1ed3b529b52ec2e1759048946e2bbafd98efbff35951043064b0d907b826-image.png)



### 代码


#### recursive

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode ReverseList(ListNode head) {
        if(head ==null || head.next ==null){
            return head;
        }
        //递归
        ListNode newHead = ReverseList(head.next);
        //回溯
        head.next.next = head;
        head.next = null;     

        return newHead;
    }
}
```

##### loop

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode ReverseList(ListNode head) {
        ListNode pre = null;
        ListNode next = null;

        while(head != null){
            next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
}
```