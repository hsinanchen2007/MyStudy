### 解题思路
排序得出的下标既是需要的结果

#### 坑：注意拷贝数据，sort会改变初始数据

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    // 拷一份数据
    let defaultNums = JSON.parse(JSON.stringify(nums))

    // 返回值
    let result = []

    // 排序 （注意操作会更改原数据）
    nums.sort((a, b) => a - b)

    // 查询
    defaultNums.forEach(item => {
    result.push(nums.findIndex(items => items === item)) // 下标值则是需要的值
    })
    
    return result
};
```