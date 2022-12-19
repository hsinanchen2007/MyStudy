# 不用额外空间
1. 若要求返回的二维数组元素个数不等于原数组元素个数，那么肯定不能输出重塑数组
2. 两层遍历二维数组，初始化新数组行序号row，列序号column，数组list，子数组subList，在内层循环j（二维数组行）是递增的，因此递增column，将元素添加到子数组subList，当column等于c时，表示一行已完成，将subList添加到list里，此时行序号row应加一，column初始化为0，遍历结束即可
``
/**
 * @param {number[][]} nums
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function(nums, r, c) {
    let m = nums.length, n = nums[0].length
    if (m * n !== r * c) return nums
    let row = 0, column = 0, list = [], subList = []
    let arr = list.slice()
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            subList.push(nums[i][j])
            column++
            if (column === c) {
                list.push(subList)
                subList = []
                row++
                column = 0
            }
        }
    }
    return list
};
```

# reduce整理出所有元素，再两层循环得出新数组，占用额外空间
```
/**
 * @param {number[][]} nums
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function(nums, r, c) {
    let m = nums.length, n = nums[0].length
    if (m * n !== r * c) return nums
    let allNums = nums.reduce((i, curr) => i.concat(curr), [])
    let list = [], subList = [], j = 0, len = allNums.length
    for(let i = 0; i < len; i++) {
        subList.push(allNums[i])
        j++
        if (j === c) {
            list.push(subList)
            subList = []
            j = 0
        }
    }
    return list
};
```
