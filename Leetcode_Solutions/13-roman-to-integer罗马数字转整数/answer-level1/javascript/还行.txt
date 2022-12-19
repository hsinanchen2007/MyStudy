![image.png](https://pic.leetcode-cn.com/b1c338fa04316db52f6a9febfa6e138a7de4ba1ee42648332032a43dfcb9bf15-image.png)



```javascript []
var romanToInt = function(s) {
  const loma = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000
  };
  let res = 0;
  for (let i = 0; i < s.length; i++) {
    let curent = s[i],
      next = s[i + 1];
    if (loma[next] > loma[curent]) {
      res += loma[s[i + 1]] - loma[curent];
      i++; //当I的后面是V的时候跳过V的循环
    } else res += loma[curent];
  }
  return res;
};
```
