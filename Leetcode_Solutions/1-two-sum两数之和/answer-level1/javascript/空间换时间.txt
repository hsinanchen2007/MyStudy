### 解题思路
1.首先考虑暴力解决时间复杂度过高，考虑其他代替方案。
2.借用哈希空间换时间。
3.两数之和就是两数的差值。
4.边查询，边insert,这里较难思考的点就是，需要考虑到，不用全部将差值计算出来后再去通过哈希查询，因为你当前找不到匹配的，后边有和你匹配的一定会出来的。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let temObj ={}
    for(let i =0; i< nums.length; i++){
        let temp = target - nums[i]
        if(temObj.hasOwnProperty(temp)){
            return [temObj[temp] ,i];
        }
        temObj[nums[i]] = i;
    }
    throw new Error('meizhodao')
};
```