### 思路

- 标签：链表、递归
- 这道题可以使用递归实现，新链表也不需要构造新节点，我们下面列举递归三个要素
- 终止条件：两条链表分别名为 `l1` 和 `l2`，当 `l1` 为空或 `l2` 为空时结束
- 返回值：每一层调用都返回排序好的链表头
- 本级递归内容：如果 `l1` 的 `val` 值更小，则将 `l1.next` 与排序好的链表头相接，`l2` 同理
- $O(m+n)$，$m$ 为 `l1`的长度，$n$ 为 `l2` 的长度

### 代码

```Java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) {
            return l2;
        }
        if(l2 == null) {
            return l1;
        }

        if(l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}
```
```JavaScript []
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    if(l1 === null){
        return l2;
    }
    if(l2 === null){
        return l1;
    }
    if(l1.val < l2.val){
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    }else{
        l2.next = mergeTwoLists(l1, l2.next);
        return l2;
    }
};
```

### 画解




<![frame_00001.png](https://pic.leetcode-cn.com/7ddaf1beb64fdef4393cc6ebd0dfd1723b97d2c183ab5c8414c0898027623a00-frame_00001.png),![frame_00002.png](https://pic.leetcode-cn.com/f4b7e354473d2bf28283ac3c410bc81e9f7ecb35f14189de9fadc041452c2653-frame_00002.png),![frame_00003.png](https://pic.leetcode-cn.com/001e4c2fdd8b5d725bc25df6373f7590404d9ef16efdea6e3700b68c23500a7a-frame_00003.png),![frame_00004.png](https://pic.leetcode-cn.com/5fbc72d56f32a8b1bc34db4bbd1588abebb4942348d8ea22fdb60724c8e4986c-frame_00004.png),![frame_00007.png](https://pic.leetcode-cn.com/912a9fef02ca9d5b4cdb891c2500f496a5f329adafa22f8ecdfd1cb591434b92-frame_00007.png)>

