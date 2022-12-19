### 解题思路
此题要使矩阵重塑，重塑后的矩阵行列数的乘积要等于二维数组行列的乘积
1.获取二维数组的行数和列数
2.将二维数组按行遍历顺序变成一维数组aa
3判断能否重塑

### 代码

```javascript
/**
 * @param {number[][]} nums
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function(nums, r, c) {
    let a = nums.length;
    let b = nums[0].length;
    let res = []
    let aa = []
    nums.forEach(item => {
        item.forEach(v => {
             aa.push(v)   
        })
    })
    if((a*b) == (r*c) ){
        for(let i = 0; i < r; i++){
            res.push(aa.splice(0,c))
        }
    }else {
        return nums;
    }
    return res;
};
```