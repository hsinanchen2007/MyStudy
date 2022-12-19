### 解题思路
1、用Int越界；
2、用Long越界；
3、用BigInteger，通过；

这个题目不知道想考察啥，感觉考察到long，用数学算更有考察意义。

### 代码

```java
import java.math.BigInteger;
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

        ListNode ret = null;

        if ((l1 == null) && (l2 == null)) {
            return ret;
        }
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }

        StringBuffer sb1 = new StringBuffer();
        while (l1 != null) {
            sb1.append(Integer.valueOf(l1.val).toString().charAt(0));
            l1 = l1.next;
        }
        sb1.reverse();

        BigInteger bigInt1 = new BigInteger(sb1.toString());

        StringBuffer sb2 = new StringBuffer();
        while (l2 != null) {
            sb2.append(Integer.valueOf(l2.val).toString().charAt(0));
            l2 = l2.next;
        }
        sb2.reverse();
        BigInteger bigInt2 = new BigInteger(sb2.toString());

        BigInteger sum = bigInt1.add(bigInt2);

        String sumStr = sum.toString();
        int i = sumStr.length() - 1;
        ListNode preNode = null;
        while (i >= 0) {
            ListNode curNode = new ListNode(Integer.valueOf(sumStr.substring(i, i + 1)));
            if (preNode != null) {
                preNode.next = curNode;
            } else {
                ret = curNode;
            }

            preNode = curNode;
            i = i - 1;
        }

        return ret;
    }
    
}
```