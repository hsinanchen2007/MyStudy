### 解题思路
思路比较简单，直接在循环中遍历每个结点判断是否应该删除即可。注意，为了删除连续的重复元素，删除的时候应该再使用一个循环。

时间复杂度：O(n)。
空间复杂度：O(1)。

### 代码

```java
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode temp = head;
        while(temp != null)
        {
            ListNode old = temp;
            temp = temp.next;
            while(temp != null && old.val == temp.val)
            {
                old.next = temp.next;
                temp = old.next;
            }
        }
        return head;
    }
}
```