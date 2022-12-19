> 回溯算法是指在包含问题的所有解的解空间树中，按照深度优先搜索的策略，从根结点出发深度探索解空间树。当探索到某一结点时，要先判断该结点是否包含问题的解，如果包含，就从该结点出发继续探索下去，如果该结点不包含问题的解，则逐层向其祖先结点回溯。

首先我们假设输入一个`MxN`的矩阵，我们从`A00`开始，先往下(即左下标`i + 1`)，再往右(即右下标`j + 1`)，当我们遇到`i = m - 1` 或者 `j = m - 1`时，说明我们已经到矩阵的最下侧或者最右侧，此时只能一条路往右或者往下抵达终点，路线数量加一并回溯至上一节点。下面以`3x3`的矩阵为例画图，图中黄色的节点即为已寻找到的单独路线。

![image.png](https://pic.leetcode-cn.com/63e94ae664db99266eaac328e64b597da044d05aee28c4a2406648b10cfbaaf9-image.png)

根据上述思路，我们可以以递归的方式得出如下代码:
```javascript []
var uniquePaths = function (m, n) {
    // 若只有一条路线
    if (m === 1 || n === 1) {
        return 1;
    }
    const findPath = function(i, j) {
        // 计算每一节点的路线数
        let count = 0;
        if (i + 1 < m - 1) {
            // 若未至底侧，继续进入底侧节点
            count += findPath(i + 1, j);
        } else {
            count++;
        }
        if (j + 1 < n - 1) {
            // 若未至右侧，继续进入右侧节点
            count += findPath(i, j + 1);
        } else {
            count++;
        }
        return count;
    }

    return findPath(0, 0);
};
```
上面的代码可以得出计算出结果，但是在提交时会发现运行结果超出限制。再仔细观察我们所画的流程图，我们会发现节点`A11`在图中递归运行了两次。我们可以添加一个数组来储存节点的路线数量，在第二次运行至此节点时，我们返回之前存储的数值，不用再进入节点计算。

优化过的代码如下：
```javascript []
var uniquePaths = function (m, n) {
    // 若只有一条路线
    if (m === 1 || n === 1) {
        return 1;
    }
    // 存储已遍历的值
    const store = [...Array(m)].map(() => [...Array(n)]);
    const findPath = function(i, j) {
        if (store[i][j]) {
            return store[i][j];
        }
        // 计算每一节点的路线数
        let count = 0;
        if (i + 1 < m - 1) {
            // 若未至底侧，继续进入底侧节点
            count += findPath(i + 1, j);
        } else {
            count++;
        }
        if (j + 1 < n - 1) {
            // 若未至右侧，继续进入右侧节点
            count += findPath(i, j + 1);
        } else {
            count++;
        }
        store[i][j] = count;
        return count;
    }

    return findPath(0, 0);
};
```
