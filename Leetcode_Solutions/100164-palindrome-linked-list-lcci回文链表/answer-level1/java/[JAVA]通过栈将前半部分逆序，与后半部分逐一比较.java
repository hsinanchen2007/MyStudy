### 解题思路
解题思路请看注释
![截屏2020-03-23下午6.45.16.png](https://pic.leetcode-cn.com/24351169c34427decb72ebb99ace238c9ff254e3d32da8a8f68b23f1072ee35b-%E6%88%AA%E5%B1%8F2020-03-23%E4%B8%8B%E5%8D%886.45.16.png)

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
    public static boolean isPalindrome(ListNode head) {
        ListNode temp = head;
        int count = 0;
        while (temp != null) {
            temp = temp.next;
            //统计链表中元素的个数
            count++;
        }
        temp = head;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < count / 2; i++) {
            //将前半段的元素入栈
            stack.push(temp.val);
            temp = temp.next;
        }
        //如果元素的个数为奇数，则最中间的元素不需要进行比较，指针后移
        if (count % 2 != 0) temp = temp.next;
        boolean flag = true;
        while (!stack.isEmpty()) {
            if (stack.pop() == temp.val) {
                //将栈中元素逐一弹出与指针的元素进行比较，相同则继续循环，不同则返回false并且break
                temp = temp.next;
                continue;
            }
            flag = false;
            break;
        }
        return flag;
    }
}
```