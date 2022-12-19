![8.png](https://pic.leetcode-cn.com/536c967f8b76e63c5cf5b8e03d679f941407dc259f0f1545e24547cb9eff9a77.jpg)

### 思路

* 标签：`假节点`
* 链表的数字正好是倒序，可以直接从左往右加，将结果存放在一个新的链表中。
* 要考虑到进位，使用进位变量 carry 存放进位值
* 需要使用一个假头节点 dummyHead 来链接「结果链表」，假节点相当于一个桩，栓着这根绳子（链表）
* 时间复杂度：O(n)
* 空间复杂度：O(n)，需要额外的链表来存放结果链表，长度为 N

### 代码
```Java []
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode curr = dummyHead;
        int carry = 0; // 用于进位，进位为 1，默认为 0
        while (l1 != null || l2 != null) { // 使用 ||，因为 l1 和 l2 可能长度不一致
            int x = (l1 == null ? 0 : l1.val); // 三元运算符避免 l1.val 报错
            int y = (l2 == null ? 0 : l2.val);
            int sum = x + y + carry; // carry 为 0 时，对结果没有影响
            carry = sum / 10; // 取整，0 或 1
            curr.next = new ListNode(sum % 10); // 取余
            curr = curr.next;
            if (l1 != null) // 不能为空，否则 l1.next 报错
                l1 = l1.next; // l1.next 可以为空
            if (l2 != null)
                l2 = l2.next; // l2.next 与 l1.next 均为空时，结束循环，避免无限循环
        }
        if (carry == 1) { // [5] + [5] -> [10]
            curr.next = new ListNode(carry);
        }
        return dummyHead.next;
    }
}
```
```JavaScript []
var addTwoNumbers = function (l1, l2) {
    let dummyHead = new ListNode(0);
    let curr = dummyHead;
    let carry = 0;
    while (l1 !== null || l2 !== null) {
        let x = (l1 === null ? 0 : l1.val);
        let y = (l2 === null ? 0 : l2.val);
        let sum = x + y + carry;
        carry = parseInt(sum / 10);
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (l1 !== null)
            l1 = l1.next;
        if (l2 !== null)
            l2 = l2.next;
    }
    if (carry === 1) {
        curr.next = new ListNode(carry);
    }
    return dummyHead.next;
};
```
### 画解
<![1.png](https://pic.leetcode-cn.com/e7a8aca723ca4e8dc06a2cf835a57d1cb8750e30009564e7ae7ec7e8555ff219-file_1564573991034),![2.png](https://pic.leetcode-cn.com/044278bf7fe787513d142ec900c7eaeadd39243e721aaf242f6b31e4ff368322-file_1564573991027),![3.png](https://pic.leetcode-cn.com/826a5c9807e8eb535553420923fdab183e3a18334afb8991d456cdec661402a5-file_1564573991037),![4.png](https://pic.leetcode-cn.com/e1590be909440ead7a21a3f68044a5572d6200d3776303047c5a85a31c39b2e3-file_1564573991039),![5.png](https://pic.leetcode-cn.com/ca324918b134aa8286f92acb607124302483fac826770f472075037dbaeae242-file_1564573991042),![6.png](https://pic.leetcode-cn.com/44f1a5460b20d1bb96c1b4c3cab307aa166c9db28cb21366be8c7b4ca2b35738-file_1564573991044),![7.png](https://pic.leetcode-cn.com/7e16d7581b215df2b0b4e821c06a72bd92993fa00a6edb392623e8d5eee93524-file_1564573991047),![8.png](https://pic.leetcode-cn.com/6b9042b52ebb1cd455d40b5024ac286a54dbc41602885f6f8d7b25d2129dbcb2-file_1564573991051)>
### 测试用例

输入 | 输出 | 情况
---|---|---
l1 = [0, 1]，l2 = [0, 1, 2] | [0, 2, 2] | 长度不一致
l1 = []，l2 = [0, 1] | [0, 1] | 一个为空
l1 = [9, 9]，l2 = [1] | [0, 0, 1] | 进位