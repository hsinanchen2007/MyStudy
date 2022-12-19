JavaScript 三种解法：

1. 嵌套for循环暴力解
```
var repeatedNTimes = function(a) {
    for(let i=0; i<a.length-1;i++) {
      for(let j = i+1; j<a.length; j++) {
        if(a[i] === a[j]) {
          return a[i];
        }
      }
    }
};
```

2. 利用额外空间备份判定
```
var repeatedNTimes = function(a) {
  var temp = {};
  for(let i=0; i<a.length; i++) {
    if(temp[a[i]]) return a[i];
    temp[a[i]] = true;
  }
};
```

3. 利用规则，如最高票的思路，重复元素要么间隔，要么相近，有一个特例是四个元素时会首位两端分布
```
var repeatedNTimes = function(a) {
  for (let i = 0; i < a.length - 1; i++) {
    if (a[i] === a[i + 1]) return a[i];
  }
  // [1,3,2,3] || [3,1,2,3]
  if (a[0] === a[2] || a[0] === a[3]) {
    return A[0];
  }
  return a[1];
};

```



