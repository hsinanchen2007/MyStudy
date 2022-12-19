### 解题思路
常规方法

### 代码

```javascript
let missingNumber = (nums) => {
  let len = nums.length
  if (nums[0] !== 0) {
    return 0
  }
  for (let i = 0; i<len - 1; i++) {
    if (nums[i + 1] - nums [i] !== 1) {
      return nums[i] +1
    }
  }
  return nums[len -1] +1
};
```