![2019123103.PNG](https://pic.leetcode-cn.com/3104aa28cbafdce8e880b7bcf0f7b03a23f4f8d301b41e73db439650ca44bf0e-2019123103.PNG)

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
        while(p !=null) {
        	outSum = (int) (outSum + p.val*Math.pow(2, count));
        	count -= 1;
        	p=p.next;
        }
        return outSum;
    }
}
```