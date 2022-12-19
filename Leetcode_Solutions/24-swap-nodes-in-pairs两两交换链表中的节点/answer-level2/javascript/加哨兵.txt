### 解题思路
![IMG_0032.JPG](https://pic.leetcode-cn.com/4ca2f8051f162e6df89c748ff94fe64b9088ccf5f861d670a64b8771bb7091cc-IMG_0032.JPG)
![IMG_0033.JPG](https://pic.leetcode-cn.com/093a8c2956b29f17ce888b9e6b47058b91b27f5d5b0d2b2f4029cbdff0c5ef45-IMG_0033.JPG)
### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    let shaob = new ListNode(0); // 添加哨兵 加0
    shaob.next = head;
    let shao = shaob
    while(shao.next != null && shao.next.next != null) {
        let start = shao.next; // 代表第一次的1
        let end = shao.next.next; // 代表第一次的2
        shao.next = end; // 0 指向 2
        start.next = end.next; // 1 指向 3
        end.next = start; // 2 指向 1
        shao = start; // 将此时的1 也就是交换后的1当哨兵 继续循环
    }
    return shaob.next // 返回的是最初哨兵的前一个 就是链表头
};
```