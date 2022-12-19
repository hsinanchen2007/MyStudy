### 解题思路
![image.png](https://pic.leetcode-cn.com/63d6cb8bd3eacdbcdc722c7e33b4474d44558e1d109401a12b55dc2c04ba0bd7-image.png)


### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} start
 * @return {boolean}
 */
var canReach = function(arr, start) {
  let flag = false
  let memo = {}
  function reach(arr,index){
    if(index<0 || index>arr.length-1 || memo[index]) return;
    if(arr[index]==0) {
      flag = true
      return;
    }
    memo[index] = true

    reach(arr, index-arr[index])
    reach(arr, index+arr[index])

  }

  reach(arr, start)
  return flag
};
```