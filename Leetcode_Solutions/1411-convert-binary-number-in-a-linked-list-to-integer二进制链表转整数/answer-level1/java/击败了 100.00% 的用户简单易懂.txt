### 解题思路
此处撰写解题思路
构建Stingbuilder遍历head链表将结点添加到sb中对其进行操作
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
        StringBuilder sb = new StringBuilder();
        while(head != null){
            sb.append(head.val);
            head = head.next;
        }
        double sum = 0;
        int length = sb.length();
        
        for(int i = 0; i < sb.length(); i++){
            sum += (sb.charAt(i) - '0') * Math.pow(2,length - 1);
            length--;
        }
        return (int)sum;
    }
}
```