### 解题思路
&emsp;&emsp;我这里用一个数组作为返回值，多加了一维只是为了思路更清晰，如果理解了可以像官方一样省去。`A[0]`作为移动的步数，`A[1]`表示当前结点需要的金币数量，正数表示余出，负数表示缺少。
&emsp;&emsp;一个节点也就3个状态 1.硬币多出; 2.硬币刚好满足该子树; 3.硬币缺少。如果是1或者3都表示硬币要向上走一个节点或者硬币要从上往下走一个节点，要走的路程就是 `abs(A[1])`, 如果是2就不需要额外的路程也即是 `A[0] = 0 `。将树后序遍历进行自底向上的求值即可。

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var distributeCoins = function(root) {
    function dfs(root){
        //返回的数组表示移动的步数和需要的金币数，正数表示可以给出的，负数表示需要
        if(root == null) return [0, 0];
        let left = dfs(root.left),
            right = dfs(root.right),
            need = right[1] + left[1] + root.val - 1;
        return [Math.abs(need) + left[0] + right[0], need]
    }
    return dfs(root)[0];
};
```