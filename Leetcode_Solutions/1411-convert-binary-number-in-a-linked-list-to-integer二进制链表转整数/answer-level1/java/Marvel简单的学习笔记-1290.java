### 解题思路
最基本的二进制转十进制。

### 代码

```java
class Solution {
    public int getDecimalValue(ListNode head) {
        int decimal = 0;
        while(head != null)
        {
            decimal = decimal * 2 + head.val;
            head = head.next;
        }
        return decimal;
    }
}
```