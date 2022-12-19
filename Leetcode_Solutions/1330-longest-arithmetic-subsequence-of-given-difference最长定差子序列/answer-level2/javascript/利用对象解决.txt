
![image.png](https://pic.leetcode-cn.com/3df4a9370df9b2898533a1f2fae1b23cb98203193a921e8b0293e6aedf3b43f1-image.png)
```js
/**
 * @param {number[]} arr
 * @param {number} difference
 * @return {number}
 */
var longestSubsequence = function(arr, difference) {
  var maxnum=0;
  var obj={};
  for(var i of arr){
    if(obj[i-difference]){
      obj[i]=obj[i-difference]+1;
    }
    if(!obj[i]){
      obj[i]=1
    }
    if(obj[i]>maxnum){
      maxnum=obj[i]
    }
  }
  return maxnum;
};
```

