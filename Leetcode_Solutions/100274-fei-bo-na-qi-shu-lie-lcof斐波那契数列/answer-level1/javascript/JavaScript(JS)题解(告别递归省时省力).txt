### 解题思路
顺着来想更容易，每次结果进入result时就取模。

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var fib = function (n) {
    if (n === 0) return 0
    if (n === 1) return 1
    let result = [0, 1]
    for (let i = 2; i <= n; i++) {
        let result[i] = result[i - 2] + result[i - 1];
        if(result[i] >= 1000000007) { 
            result[i] = result[i] % 1000000007;
        }
    }
    return result[n]
};
```
![搜索框传播样式-标准色版.png](https://pic.leetcode-cn.com/5b693dce2ea930fe7d095fbb126cc9e8b0d109de3e59c4f09c898d62a09d7a9b-%E6%90%9C%E7%B4%A2%E6%A1%86%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
