
### [365\. 水壶问题](https://leetcode-cn.com/problems/water-and-jug-problem/)

Difficulty: **中等**


有两个容量分别为 *x* 升 和 *y* 升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 *z* 升 的水？

如果可以，最后请用以上水壶中的一或两个来盛放取得的 *z* 升水。

你允许：

*   装满任意一个水壶
*   清空任意一个水壶
*   从一个水壶向另外一个水壶倒水，直到装满或者倒空

**示例 1:** (From the famous )

```
输入: x = 3, y = 5, z = 4
输出: True
```

**示例 2:**

```
输入: x = 2, y = 6, z = 5
输出: False
```


#### Solution

Language: **JavaScript**

#### 一、DFS解法

**解题思路：**

我们要通过 `X` 升水壶和 `Y` 升水壶来得到 `Z` 升水，而根据题意我们对 `X` 水壶和 `Y` 水壶操作限制如下：
*   装满任意一个水壶
*   清空任意一个水壶
*   从一个水壶向另外一个水壶倒水，直到装满

那么我们所有能做的操作如下：
* 将 `X` 水壶装满
* 将 `X` 水壶倒空
* 将 `Y` 水壶装满
* 将 `Y` 水壶倒空
* 将 `X` 水壶的水倒向 `Y` 水壶，直至 `Y` 水壶倒满或者 `X` 水壶倒空
* 将 `Y` 水壶的水倒向 `X` 水壶，直至 `X` 水壶倒满或者 `Y` 水壶倒空

那么不同的操作会得到不同的储水状态，我们可以用深度优先遍历的方法，来遍历所有的储水状态，如果能够得到 Z 升水，则返回 `true`，否则返回 `false`。另外这里我们可以用 `map` 或者 `set` 来记录遍历过的储水状态，防止重复遍历以及可能出现的无限循环。

**代码**

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
    let stack = [[0, 0]], set = new Set();
    while (stack.length) {
        let [remainX, remainY] = stack.pop();
        if (remainX === z || remainY === z || remainX + remainY === z) return true;
        if (set.has(remainX + "#" + remainY)) continue;
        set.add(remainX + "#" + remainY);
        // 把 x 壶倒满
        stack.push([x, remainY]);
        // 把 y 壶倒满
        stack.push([remainX, y]);
        // 把 x 壶倒空
        stack.push([0, remainY]);
        // 把 y 壶倒空
        stack.push([remainX, 0]);
        // 把 x 壶水倒向 y 壶，直至 x 壶倒空，或者 y 壶倒满
        stack.push([remainX - Math.min(remainX, y - remainY), remainY + Math.min(remainX, y - remainY)])
        // 把 y 壶水倒向 x 壶，直至 y 壶倒空，或者 x 壶倒满
        stack.push([remainX + Math.min(remainY, x - remainX), remainY -  Math.min(remainY, x - remainX)])
    }
    return false;
};
```
**复杂度分析**
- 时间复杂度：`O(x*y)`，所有的状态数和为 `x * y`种
- 空间复杂度：`O(x*y)`，所有的状态数和为 `x * y`种，哈希集合最多存储`O(x*y)`项


#### 二、数学解法（贝祖定理）

**解题思路：**

由题意可知我们的操作只能是增加 `X` 升水、减少 `X` 升水、增加 `Y` 升水、减少 `Y` 升水。那么如果存在`ax + by = z`，`a、b` 为整数，则可以得到 `Z` 升水。
根据 [贝祖定理](https://zh.wikipedia.org/wiki/%E8%B2%9D%E7%A5%96%E7%AD%89%E5%BC%8F)，如果`ax + by = z`，`a、b` 为整数，存在解，那么 `z` 一定是 `x` 与 `y` 的最大公约数的倍数。

**代码**

```javascript
​/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
    if (x + y < z) return false;
    if (x === 0 || y === 0) return  z === 0 || (x + y === z);
    const gcd = (a, b) => b === 0 ? a : gcd(b, a % b);
    return z % gcd(x, y) === 0
};
```

**复杂度分析**

- 时间复杂度：`O(log(min(x,y)))`，取决于计算最大公约数所使用的辗转相除法。

- 空间复杂度：`O(1)`，只需要常数个变量。
