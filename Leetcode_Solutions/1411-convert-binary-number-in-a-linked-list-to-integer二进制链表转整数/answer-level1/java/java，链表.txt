![2019123103.PNG](https://pic.leetcode-cn.com/a3321c87b192a434820509192a442f8ea502debdba88cc94985e2fcf01275f32-2019123103.PNG)

### 解题思路
此处撰写解题思路

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
    public int getDecimalValue(ListNode head) {
        int count = 0;
        int outSum = 0;
        ListNode p=head;
        while(p.next!=null) {
        	count +=1;
        	p = p.next;
        }
        p=head;
        while(p.next!=null) {
        	outSum = (int) (outSum + p.val*Math.pow(2, count));
        	count -= 1;
        	p=p.next;
        }
        outSum = (int) (outSum + p.val*Math.pow(2, count));
        return outSum;
    }
}
```