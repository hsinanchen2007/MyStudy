JS实现：

代码写的比较简单，其实就是找出数量关系
前后两个元素都是1
然后中间的元素 = 上一行两个元素之和（使用数组下标计算）

时间复杂度大概超过了46%的人，希望有大神提供更快的思路

```
var generate = function(numRows) {
    let result = []
    if(numRows === 0)return []
    if(numRows === 1)return [[1]]
    if(numRows === 2)return [[1],[1,1]]
    result = [[1],[1,1]]
    for(let i = 1; i < numRows -1; i++) {
        const arr = []
        result[i].forEach((item,index) => {
            if(index === 0 ) arr.push(1)
            else arr.push(result[i][index-1] + result[i][index])
            if(index === result[i].length - 1) arr.push(1)
        })
        result.push(arr)
    }
    return result
};
```
