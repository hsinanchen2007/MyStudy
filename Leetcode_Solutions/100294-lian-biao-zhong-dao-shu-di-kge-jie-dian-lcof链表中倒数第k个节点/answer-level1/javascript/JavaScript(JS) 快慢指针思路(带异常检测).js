### 解题思路
快慢指针不多谈。需要提防一手链表长度小于 k，该判断可以放在构造快指针距离的时候进行。

### 代码

```javascript
 */
var getKthFromEnd = function (head, k) {
    // 链表为空或 k 等于 0 是返回 null
    if (!head || !k) return null
    let slow = head, fast = head;
    for (let i = 0; i < k; i++) {
        // fast 为空则表明，链表长度 < k
        if (!fast) return 'k is more than length'
        fast = fast.next;
    }
    while (fast) {
        fast = fast.next;
        slow = slow.next;
    }
    return slow
};
```
![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/1ba56f7af5f2288c3d5bea5fce1d3b60e50682582e4e630358b7e86108c88b4f-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
