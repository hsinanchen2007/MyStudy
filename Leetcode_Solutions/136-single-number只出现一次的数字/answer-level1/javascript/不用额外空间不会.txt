### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 * 执行用时 :68 ms, 在所有 JavaScript 提交中击败了80.07%的用户
 * 内存消耗 :38.4 MB, 在所有 JavaScript 提交中击败了7.05%的用户
 */
var singleNumber = function(nums) {
  let obj = {}
  for(let i = 0; i< nums.length; i++){
    let prop = nums[i]
    obj[prop] = obj[prop] ? ++obj[prop] : 1
  }
  for(let prop in obj) {
    if(obj[prop] === 1) {
      return prop
    }
  }
  return -1
};
```

## 异或解法, 真特么神奇
```
参与运算的两个值，如果两个相应bit位相同，则结果为0，否则为1。

　　即：

　　0^0 = 0，

　　1^0 = 1，

　　0^1 = 1，

　　1^1 = 0

　　按位异或的3个特点：

　　（1） 0^0=0，0^1=1 0异或任何数＝任何数

　　（2） 1^0=1，1^1=0 1异或任何数－任何数取反

　　（3） 任何数异或自己＝把自己置0
```

### 代码
```
var singleNumber = function(nums) {
  let num = nums[0]
  for(let i = 1; i < nums.length; i++){
    num = num ^ nums[i]
  }
  return num
};
```
