### 解题思路
此处撰写解题思路
先把[0,k] 的求和结果放到一个数组arr, 它要求(i,j)之间的和 , 就用arr[j] - arr[i-1]
```js
  // 如 [1,2,3,4], (1,3)
  //则arr
  arr = [1,3,6,10]
  res = arr[3] - arr[0] = 10 - 1
```
![image.png](https://pic.leetcode-cn.com/ef32ef06ac6c003006d577065229d07e91c8100a422d92d583b77253e0c7f3a9-image.png)
灵魂画手,嘿嘿
一开始使用 nums.slice(i,j+1).reduce((a,b=>a+b)) 会超出时间限制呢, 循环要这么久么??
### 代码

```javascript
/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
  this.arr = []
  let sum = 0
  nums.forEach(item => {
    let newVal = sum + item
    this.arr.push(newVal)
    sum = newVal
  })
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    if(i === 0) return this.arr[j]
    return this.arr[j] - this.arr[i - 1]
};

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(i,j)
 */
```