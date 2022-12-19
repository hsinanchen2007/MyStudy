- 这道题如果从dp的角度考虑还是挺明显的:
    - count[i]表示节点i去掉和为0的子树后的子树节点数；sum[i]表示节点i的子树和
        - count[i] = count[i.left] + count[i.right] + 1
        - sum[i] = sum[i.left] + sum[i.right] + val(i);
- 但是这样直观的思路是从根到叶子的，而题目只提供了叶子到根的关系
    - 那么其实就可以从叶子往根处理，即自底向上的动规 

![image.png](https://pic.leetcode-cn.com/343888e7d165d053349ccffe7765af67880fc145e0c63ea84ce19788e19cebed-image.png)

- `time: O(n), space: O(n)`，js实现如下


```js
var deleteTreeNodes = function(nodes, parent, value) {
    const count = new Array(nodes).fill(0);
    const sum = new Array(nodes).fill(0);

    for (let i = nodes - 1; i >= 0; i--) {
        const p = parent[i];

        sum[i] += value[i];
        if (p >= 0) sum[p] += sum[i];

        if (sum[i] === 0) count[i] = 0;
        else count[i] += 1;
        if (p >= 0) count[p] += count[i];
    }
    return count[0];
};
```