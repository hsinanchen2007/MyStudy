### 解题思路
迭代与递归解法。递归解法可以跑通测例，但是提交会栈溢出。
迭代法思路：当序列长度为 1 时，一定会留下唯一的那个元素，它的编号为 0，因此lastRemaining(1, m)=0。
由 `lastRemaining(n, m) = (m + lastRemaining(n-1, m)) % n` 可得迭代解法。
![Snipaste_2020-03-30_08-51-07.png](https://pic.leetcode-cn.com/2ef54f7e9538a849db65bfe77e6481b7af142648db1ff0af4be90f07b342f5af-Snipaste_2020-03-30_08-51-07.png)


### 代码
迭代
```javascript
var lastRemaining = function(n, m) {
    let result = 0;
    for(let i = 2; i <= n; i++) {
        result = (m + result) % i;
    }
    return result
};
```

递归(**爆栈**)
```javascript
var lastRemaining = function (n, m) {
    return recur(n, m)
};

function recur (n, m) {
    if (n === 1) return 0
    let result = recur(n - 1, m)
    return (m + result) % n
}
```
![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/14f9a8660e2aa1890cf341ad06493fa69c11682e2eeaf8d85e72f656fd30ec80-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
