### 解题思路
1.一层层递归，直到最后一个节点
2.最后一个节点为1，一层层返回，每层返回的值+1
3.如果当前层的值与k相等，即为所找的值

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
    private int res=0;
    public int kthToLast(ListNode head, int k) {
        helper(head,k);
        return res;
    }
    private int helper(ListNode node,int k){
        if (node.next==null) {
            if (k==1)
                res=node.val;
            return 1;
        }
        int v=helper(node.next,k)+1;
        if (v==k)
            res=node.val;
        return v;
    }
}
```