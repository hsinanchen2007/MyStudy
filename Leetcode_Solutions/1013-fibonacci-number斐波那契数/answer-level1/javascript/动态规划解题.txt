### 解题思路
这个题目很经典，用递归做很简单，但是太消耗性能了。

用动态规划可以极大的提高性能, 设置一个缓存res，res[i] = res[i-1] + res[i-2]  ,每次遍历的结果都存放在res中，最后返回即可。

### 代码

```javascript
var fib = function(N) {
  var res = new Array(N+1)  //用于缓存
  for (let i = 0; i < N+1; i++) {
    if (i < 2) {
      res[i] = i 
    } else {
      res[i] = res[i-1] + res[i-2]
    }
  }
  return res[N]
};
```