### 解题思路
利用栈先进后出的特性来实现从尾到头打印。为了返回数组，在将元素进栈时顺便统一个数，方便声明对应大小的数组。

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
    public int[] reversePrint(ListNode head) {
        Stack<Integer> stack = new Stack<Integer>();
        ListNode pHead = head;
        int i = 0;
        while(pHead != null) {
            i++;
            stack.push(pHead.val);
            pHead = pHead.next;
        }
        int[] temp = new int[i];
        for(int j=0; j<i && !stack.isEmpty(); j++) {
            temp[j] = stack.pop();
        }
        return temp;
    }
}
```