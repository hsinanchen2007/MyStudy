### 解题思路

由于「整数的各个数位按照 高位在 ``链表`` 头部、低位在 ``链表`` 尾部 的顺序排列」，所以给这个整数加一需要从 ``链表`` 的尾部开始加，我们可以利用 ``递归`` 的特点来完成这个思路：

- ``递归`` 到最后一个节点，加一
- 加一的时候算上进位
- 如果 ``递归`` 结束之后，进位还存在，那么新建一个节点连接递归生成的 ``链表``

![image.png](https://pic.leetcode-cn.com/a8718285627d20a92952645db6f12c49ae3d89433132612eda9ee16c7a9fc89f-image.png)

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
var plusOne = function(head) {
    const helper = (head) => {
        // 递归到头了，返回 null
        if (!head) {
            return null
        }
        // 这里的 next 可以理解为上一段链表
        let next = helper(head.next)
        // 如果是链表的最后一个数字就要加一
        let temp = head.next ? 0 : 1
        let val = head.val
        // 计算当前节点的值
        head.val = (val + temp + carry) % 10
        // 计算进位
        carry = Math.floor((val + temp + carry) / 10)
        // 返回当前节点
        return head
    }
    // 初始化进位
    let carry = 0
    // 调用递归以找到加1的结果
    let node = helper(head)
    // 如果递归结束之后进位数不为空
    // 那么把它补到 node 前面
    if (carry) {
        let next = node
        node = new ListNode(carry)
        node.next = next
    }
    return node
};
```