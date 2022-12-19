## 重述问题

有两个指针分别指向两个链表的头（headA, headB），而这两个链表可能有一个公共的尾巴（commonTail）。需要在 O(1) 的空间复杂度下找到公共尾巴的第一个节点。

## 分析

令 L 代表链表的长度，令 headA' 为 headA 除去 commonTail 的部分，以及 headB' 为 headB 出去 commonTail 的部分。

因为 L(headA) + L(headB) = L(headB) + L(headA)。

又：

- headA + headB = (headA' + commonTail) + (headB' + commonTail) = (headA' + commonTail + headB') + commonTail

- headB + headA = (headB' + commonTail) + (headA' + commonTail) = (headB' + commonTail + headA') + commonTail

注意到 

- L(headA' + commonTail + headB') = L(headB' + commonTail + headA')

所以，如果用指针 ab 先去遍历 headA，再去遍历 headB，同时用指针 ba 先去遍历 headB，再去遍历 headA，那么这两个指针必定在 第二次到达 commonTail 时相遇。

```
ab ==> (headA' + commonTail + headB') + commonTail
                                        ↑
                                        ab
                                        相遇！
                                        ba
                                        ↓
ba ==> (headB' + commonTail + headA') + commonTail
```

如果 L(commonTail) = 0，那么可以把 commonTail 替换成 null，以上分析依然成立。

## 代码实现

想清楚了这个等式关系，4 行代码即可实现：

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let [ab, ba] = [headA, headB];

    while (true) {
        if (ab === ba) return ab;

        [ab, ba] = [ab ? ab.next : headB, ba ? ba.next : headA];
    }
};
```

## 复杂度分析

### 时间复杂度

最坏的情况下，O(2n)

### 空间复杂度

只需要两个指针的空间，O(1)

![image.png](https://pic.leetcode-cn.com/b74b94a1823f2873ab7b55486d62e34ef92ffef2b3fd09d508fa7271e846ae86-image.png)
