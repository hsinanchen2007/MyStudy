### 解题思路
递归实现，先递归调用到最后，然后设置一个标志计算递归返回的层次，当标志等于k时，返回value

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
    private int index = -1;
    public int kthToLast(ListNode head, int k) {
        //存递归返回的结果
        int result = 0;

        if (head.next != null) {//若还有下一层，递归调用
            result = kthToLast(head.next, k);
            index++;//递归返回后标志增加
        } else {//没有下一层，意味着到了结尾，标志变为1
            index = 1;
        }
        
        if (index == k)//若标志等于k，返回value
            return head.val;

//返回递归结果
        return result;
    }
}
```