### 解题思路
快慢双指针，间隔k的距离，当快指针遍历到队尾结束两个指针遍历，慢指针指的就是需要的值
感觉应该是最快的，只花了一次遍历的时间

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
        ListNode fastList=head;
        ListNode slowList=head;
        int num=0;
        while(fastList!= null){
            fastList=fastList.next;
            num++;
            if(num==k)
                break; 
        }
        while(fastList!= null){
            fastList=fastList.next;
            slowList=slowList.next;
        }
        return slowList.val;
    }
}
```