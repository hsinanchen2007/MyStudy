### 解题思路

排序, 循环 前后两数相减 得出 最小值, 再次循环 匹配最小值,得出数组

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number[][]}
 */
var minimumAbsDifference = function(arr) {
  arr = arr.sort((a,b) => a-b)
  let list = []
  let min = arr[1] - arr[0]
  for(let i = 0; i < arr.length - 1; i ++){
      let sub =  Math.abs(arr[i] - arr[i+1])
      if(sub < min) min = sub
  }
  for(let i = 0; i < arr.length - 1; i ++){
      let sub =  Math.abs(arr[i] - arr[i+1])
      if(sub === min) list.push([arr[i],arr[i+1]])
  }
  
  return list
};
```