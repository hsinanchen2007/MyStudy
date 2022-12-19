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
    public boolean isPalindrome(ListNode head) {
    if(head == null)
        return true;
    ListNode temp = head;
    int length = 0;
    while(temp != null)
    {
        length++;
        temp = temp.next;
    }
    int[] nums = new int[length];
    int count = length-1;
    temp = head;
    while(temp != null)
    {
        if(count > 0)
            nums[count--] = temp.val;
        else
            nums[count] = temp.val;
        temp = temp.next;
    }

    temp = head;
    count = 0;
    while(temp != null)
    {   
        if(count < length-1)
        {
            if(temp.val != nums[count++])
                return false;
        }
        else
        {
            if(temp.val != nums[count])
                return false;
        }
        temp = temp.next;
         
    }
    return true;
    }
}
```