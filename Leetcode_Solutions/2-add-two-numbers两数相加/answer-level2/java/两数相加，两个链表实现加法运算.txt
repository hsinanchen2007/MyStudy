### 解题思路
![两数相加.JPG](https://pic.leetcode-cn.com/a47442996e8e185f8919d31af9f0d089fdbbe7c000045ac9328f6b5fba1937da-%E4%B8%A4%E6%95%B0%E7%9B%B8%E5%8A%A0.JPG)
此题的关键是自己实现一个两数的加法。
之前以为可以通过数学运算实现，发现无论是int还是long都会存在溢出，无法完成所有测试案例。
1、加法思路很简单，像解小学数学加法一样，个位和个位相加，十位和十位相加，类推。使用一个进位符c，若每位的两个数相加的和大于9，则，c=1；在当次相加完后，c归0；

2、取数的时候要保证两个ListNode的位都对应上，则取数都在同一个循环中去取，如果当前节点非空则取出值且当前节点指向下一个节点，若当前节点为空则取值为0。循环的跳出点是当两个当前节点的取值都为空时。

3、存数的时候也需要指定两个节点，一个是需要返回的节点ListNode r，它指向第一个节点；还有一个是存储当前计算的值的节点。初始化条件当r为null，则将第一个数存入r，再令current = r，以后每次存值的时候都是current移向下一个节点。

最后如果输入的两个ListNode都遍历完了，但是进位符c还为1，说明需要再进一位，则在返回的r后再添加1（相当于最高位是1，也只会是1）。

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
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            int n1,n2,n3;
            // 初始化进位符为0
            int c = 0;
            ListNode r = null;
            ListNode current = null;
            while(l1!= null || l2!= null){
                // 取数操作
                if (l1 == null){
                    n1 = 0;
                }else {
                    n1 = l1.val;
                    l1 = l1.next;
                }
                if (l2 == null){
                    n2 = 0;
                }else {
                    n2 = l2.val;
                    l2 = l2.next;
                }
                // 当前位两个数相加的和，带上进位符c
                n3 = n1+n2+c;
                // 相加完成，进位符归0
                c = 0;
                // 若每位的两个数相加的和大于9，则，c=1
                if (n3 > 9){
                    n3 %= 10;
                    c = 1;
                }
                // 存数操作
                if (r == null) {
                    r = new ListNode(n3);
                    current = r;
                } else {
                    current.next = new ListNode(n3);
                    current = current.next;
                }
            }
            // 最后如果输入的两个ListNode都遍历完了，但是进位符c还为1，说明需要再进一位，则在返回的r后再添加1
            if (c == 1){
                current.next = new ListNode(1);
            }
            return r;
        }
    }
```