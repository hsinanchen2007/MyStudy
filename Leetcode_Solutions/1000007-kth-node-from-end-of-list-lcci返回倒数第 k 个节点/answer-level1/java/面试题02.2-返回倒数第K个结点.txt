### 解题思路
解题思路为快慢指针
定义两个指针，快指针先走K步，慢指针再和快指针同步移动，当快指针.next为null时，慢指针刚好为倒数第K个结点

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
    public int kthToLast(ListNode head, int k) {
        //快慢指针思路
        ListNode aim = head;//慢指针
        ListNode pointer = head;//快指针
        while(pointer.next != null){
            if(k-1 == 0){//在快指针走了k步后，慢指针再开始移动
                aim = aim.next;
            }else{
                k--;
            }
            pointer = pointer.next;//每次都向后+1
        }
        return aim.val;
        
    }
}
```