### 解题思路
用的非常粗鲁简单的算法，分析到先进后出即想到栈的特性；


菜鸟成长中，加油

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
        Stack s = new Stack();
        int i = 0,j = 0;
        while(head!=null){
            s.push(head.val);
            i++;
            head = head.next;
        }
        int len = i;
        int[] arr = new int[i];
        while(!s.empty()&&j<i){
            arr[j] = (int)(s.pop());
            j++;
        }
        return arr;
    }
}
```