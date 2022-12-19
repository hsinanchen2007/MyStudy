### 解题思路
先排序后遍历，排序复杂度是O(nlogn)，遍历复杂度是O(n),合计复杂度是O(nlogn)。

### 代码

```javascript
var minIncrementForUnique = function (A) {
    if (!A.length) return 0
    // 递增排序
    A.sort((a, b) => { return a - b });
    // min 为当前最小值，count 为增量计数
    let min = A[0], count = 0;
    for (let i = 1; i < A.length; i++) {
        if (A[i] > min) {
            // 当前值 > min，更新 min 即可
            min = A[i];
        } else {
            // 当前值 <= min，更新 min，累计增量
            min = min + 1
            count +=  min - A[i];
        }
    }
    return count
};
```
![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/ad8d51d5b34f797ba79ee183f370d7230d5981bb51216edcf0b55d0448aea445-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
