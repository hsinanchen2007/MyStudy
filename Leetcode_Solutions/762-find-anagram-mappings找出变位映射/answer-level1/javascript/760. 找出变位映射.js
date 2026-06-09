### 解题思路

- 遍历 ``数组 B``，生成 ``数字 --> 下标`` 的 ``哈希表``
- 遍历 ``数组 A``，遇到数字就查询 ``哈希表``，并把结果 ``push`` 到数组中

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var anagramMappings = function(A, B) {
    let bMap = new Map()
    let res = []
    B.forEach((num, index) => {
        bMap.set(num, index)
    })
    A.forEach((num, index) => {
        res.push(bMap.get(num))
    })
    return res
};
```