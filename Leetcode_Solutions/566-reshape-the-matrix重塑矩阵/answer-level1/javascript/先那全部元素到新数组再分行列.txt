### 解题思路
1. 把给定的数组“拉直”，也就是转换为一维数组a1
2. 这个a1长度是否和 r * c相等，是的话继续，不是就返回nums, 因为那代表无法重构
3. 根据r 和 c 用双层循环组装一个对应行列数的数组然后返回它

### 代码

```javascript
/**
 * @param {number[][]} nums
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function(nums, r, c) {
    function flattern(arr, res){
        for(let e of arr){
            if(Array.isArray(e))flattern(e, res);
            else res.unshift(e)
        }
    }
    const res =[];
    flattern(nums, res);
    if(r*c != res.length)return nums;

    const rv = [];
    for(let i=0; i<r; i++){
        const col = [];
        for(let j=0; j<c; j++){
            col.push(res.pop());
        }
        rv.push(col);
    }
    return rv;
};
```