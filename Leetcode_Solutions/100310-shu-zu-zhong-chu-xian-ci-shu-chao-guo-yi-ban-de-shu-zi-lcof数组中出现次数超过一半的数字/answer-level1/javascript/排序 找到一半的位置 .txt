### 解题思路
排序 找到中位数
如果有小数  四舍  
避免只输入一个数字 五入的话就会变为undefined

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
   let num=nums.sort();
//    console.log((num.length/2))
   return num[Math.floor(num.length/2)]
};
```