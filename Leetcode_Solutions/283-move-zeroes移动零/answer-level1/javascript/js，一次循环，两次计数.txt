一次循环，就两种操作，零操作和循环操作，这两次数量等于数组长度，就是循环结束

```javascript
var moveZeroes = function (nums) {
  let t = 0, i = 0, len = nums.length;
  while(i + t < len){
    if(nums[i] === 0){
      nums.splice(i, 1)
      nums.push(0)
      t++;
    }else {
      i++;
    }
  }
};
```
