### 解题思路
1. 思路是每个元素都应该生成一个小于它的数组项的集合，然后方法所有数组的长度的集合

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    let res = [];

    nums.forEach(num=>{
        let arr = nums.filter(item=>num>item);
        res.push(arr.length);
    })

    return res;
};
```