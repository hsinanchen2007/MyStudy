### 解题思路
比较典型的双指针游走题目，设有两个指针 p,q ：

初始时，两个指针均指向 head。
先将 q 向后移动 k 次。此时p，q的距离为 k。
同时移动 p，q, 直到 q 指向 nullptr。此时p->val即为答案。
如下图所示：

![aa.png](https://pic.leetcode-cn.com/c11759b47df01442d2bacdc3a693531e1c5e905c741307f4bf61efffb08ce15d-aa.png)


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
        ListNode p = head;
        for(int i=0;i<k;i++){
          p = p.next;  
        }

        while(p != null){
            p = p.next;
            head = head.next;
        }

        return head.val;
    }
}
```