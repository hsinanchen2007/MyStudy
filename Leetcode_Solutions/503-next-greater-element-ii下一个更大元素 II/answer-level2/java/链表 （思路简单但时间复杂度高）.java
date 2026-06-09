### 解题思路
1.解决len <= 1的情况
2.将数组的元素放入到链表中，然后将链表最后一个next指向头部
3.以从该节点的下一个节点和其比较，直到它俩相等。

### 代码

```java
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        /* 1.返回特殊情况下的值 */
        int len = nums.length;
        int[] res = new int[len];
        if (len == 0) return res;
        if(len == 1) {
            res[0] = -1;
            return res;
        }
        /* 2.构造环形链表 */
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        for(int i=0;i<len;i++){
            curr.next = new ListNode(nums[i]);
            curr = curr.next;
        }
        curr.next = dummy.next;
        curr = curr.next;
        /* 3.从该节点的下一个节点和其比较，直到它俩相等 */
        for(int i = 0;i< len;i++){
            ListNode curNext = curr.next;
            while(curNext != curr){
                if(curNext.val>curr.val){
                    res[i] = curNext.val;
                    break;
                }
                curNext = curNext.next;
            }
            if(curNext == curr) res[i] = -1;
            curr = curr.next;
        }
        return res;
    }
}
```