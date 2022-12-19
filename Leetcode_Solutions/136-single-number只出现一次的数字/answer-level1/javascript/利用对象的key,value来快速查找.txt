### 解题思路
1. 利用对象的key,value来存储数组的元素
2. 每次循环的时候去查找一次当前元素是否存在，如果存在就删掉
3. 如果条件成立，最后只会剩下一个元素在结果对象里，然后使用for in 来取值就行了
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  var result = {}
  for (var i = 0; i<nums.length; i++) {
    if (!result[nums[i]]) {
      result[nums[i]] = nums[i]
    } else {
      delete result[nums[i]]
    }
  }
  var res;
  for (i in result) {
    res = result[i]
  }
  return res
};

```