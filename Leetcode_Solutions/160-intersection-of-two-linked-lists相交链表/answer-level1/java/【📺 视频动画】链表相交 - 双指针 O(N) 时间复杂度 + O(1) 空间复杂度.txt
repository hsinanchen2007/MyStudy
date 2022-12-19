### 双指针实现原理

![...ntersection List.mp4](1fdb1787-d06e-480d-8e23-f5c6afca410c)


#### 代码

```Java []
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null) return null;
        ListNode apointer = headA;
        ListNode bpointer = headB;
        while(apointer != bpointer){
            apointer = (apointer == null ? headB : apointer.next);
            bpointer = (bpointer == null ? headA : bpointer.next);
        }
        return apointer;
    }
}
```

#### 时间与空间复杂度

##### 时间复杂度

> 以指针 $A$ 为例，先遍历了 $A$ 链表 $N$ 个元素，后遍历 $B$ 链表 $M$ 个元素，所以花费 $O(M+N)$ 的时间

##### 空间复杂度

> 用两个 ListNode 分布存储两个指针，所以花费 $O(1)$ 的空间

##### 执行效率

 
![image.png](https://pic.leetcode-cn.com/ec611759ad367b6ee32c951a22720631cd53d28f6dcd00a1484cb192a580e7e9-image.png){:width=400}

