![image.png](https://pic.leetcode-cn.com/da30cdb7f37de3b62be28a5e26aec0d469138b1d32c68fb70dba4638f873085a-image.png)

五个月前做了一次，没考虑到k = n * size + b。（n=0,1,2...）旋转链表是周期性的，当b=0，时，直接返回head。余数b才是旋转链表的分割点。

```java
public class RotateRight {
    public static ListNode rotateRight(ListNode head, int k) {
        if (head== null || k == 0 || head.next == null) return head; //head.next == null 判断链表长度为1的情况 旋转多少次都不变。

        int m = 1;  // 链表长度至少为一时。
        ListNode temp = head;
        while (temp.next != null) {
            m++;
            temp = temp.next;
        }
        //k %= m;     // 有可能 k>m 旋转n
        int n = m - (k % m);
        if (n == m) return head;    // 如果 k = n * size n 为0，1，2...
        //System.out.println(n);
        ListNode temp2 = head;
        while (n > 1) {
            temp2 = temp2.next;
            n--;
        }
        ListNode tail = temp2.next;     // 后半部分链表断链。
        temp2.next = null;
        temp.next = head;

        return tail;
    }
}
```


