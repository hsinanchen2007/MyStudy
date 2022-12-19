### 解题思路
通过数组来存储数字出现过的次数
通过累加来获得结果

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
  //因为知道num的范围是1-100,我们直接创建一个长度为101的数组
  let temp = new Array(101);
  nums.forEach(num => {
    temp[num] = (temp[num] || 0) + 1;
  });
  //累加，每一个元素的值是[当前元素自身有几个:比它小的元素有几个]
  temp[0] = [temp[0] || 0, 0];
  for (let i = 1; i < temp.length; i++) {
    temp[i] = [temp[i] || 0, temp[i - 1][0] + temp[i - 1][1]];
  }
  //将结果映射到原数组上
  for (let i = 0; i < nums.length; i++) {
      nums[i]=temp[nums[i]][1]
  }
  return nums;
};
```