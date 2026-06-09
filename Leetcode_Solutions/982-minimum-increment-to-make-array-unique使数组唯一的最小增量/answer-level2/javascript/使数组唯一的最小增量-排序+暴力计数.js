### 解题思路
![image.png](https://pic.leetcode-cn.com/d3f44c6903bf4d4d2c669fe4ee50d549c97458d198e7afb8176dfd934392054f-image.png)

- 设计到去重的，一般第一步都是先排序；
- 明白[3,3,4,5,7], 你可以智能的把 3 变成 6；也可以暴力的把3变成4， 4变成5，5变成6，但最后发现用的次数是一样的，所以暴力没毛病

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    let count = 0;
    // 如果是一个数，那就别折腾了
    if (A.length < 2) {
        return 0;
    }
    // 排序；
    A.sort((a, b) => a - b);
    let i = 1;
    // 暴力递增；
    while (i <= A.length) {
        const target = A[i];
        // 为什么是小于等于：因为[3,3,3,4,5,7],递增两下会变成3,4,5,4,5,7
        if (target <= A[i-1]) {
            A[i] = A[i-1] + 1;
            count += A[i] - target;
        }
        i++;
        
    }
    return count;
};
```