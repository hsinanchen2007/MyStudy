### 解题思路
任你冒泡，快排花里胡哨 我只要我的Array.sort()
### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
  let res=[];
  arr.sort((a,b)=>{return a-b});
  for(let i=0;i<k;i++){
      res.push(arr[i])
  }
  return res;
};
```