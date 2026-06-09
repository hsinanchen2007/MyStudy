![返回倒数第 k 个节点.png](https://pic.leetcode-cn.com/cc5064cb10d498647ed5ae63c278b31ce87cec2d8b502ee0b0e67cce8e39f727-%E8%BF%94%E5%9B%9E%E5%80%92%E6%95%B0%E7%AC%AC%20k%20%E4%B8%AA%E8%8A%82%E7%82%B9.png)

### 解题思路
充分利用条件“给定的 k 保证是有效的”。
递归，访问到最后的节点，再往前找之前的状态。
双指针，k既是倒数的节点，也是该节点与最末尾节点的距离。
详细思路都在注释中了。朋友们可以看看行数能不能再压缩，欢迎指点。

### 代码

```java
// 递归
class Solution {
    // 开始全局变量 K 保持不变
    int K = 1;
    public int kthToLast(ListNode head, int k) {
        // 当节点在最末尾时触发返回
        if (head.next == null) return head.val;
        // 返回的值
        int val = kthToLast(head.next, k);
        // 一旦触发返回，从第一个产生返回的位置用 K 计数
        if (K++ >= k) {
            // 当到达或超过倒数第 k 时，即 K >= k 时保持返回值不变
            return val;
        } else {
            // 没到达则更新需要返回的值
            return head.val;
        }
    }
}
```

```java
// 双指针
class Solution {
    public int kthToLast(ListNode head, int k) {
        ListNode left = head, right = head;
        while (right != null) {
            right = right.next;
            // 右指针动，左指针不动，每循环一次，两个指针间的距离就会拉开
            if (k > 0) k--;
            // 当到达预定的距离后，左指针也开始动，距离保持不变
            else left = left.next;
        }
        return left.val;
    }
}
```