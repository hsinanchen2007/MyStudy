### 解题思路
思路应该很清楚了，不多描述看代码

### 代码

```java
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
       ListNode former = head, latter = head;
       while(former.next != null){
           if(--k < 1) latter = latter.next;
           former = former.next;
       }
       return latter;
    }
}
```