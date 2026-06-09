解题思路：利用位运算 n &= n - 1 及 对象实现;
由于是从0-num是递增序列，则每次使用 `n &= n - 1`去除一位1后，必定小于原数，则必能在以前序列中找到此数，将其原有的值加上去除的1可得当前数1的个数。
需要多开辟一个temp对象。

```
var countBits = function (num) {
  let arr = [0];
  let temp = {
    '0': 0
  };
  for (let i = 1; i <= num; i++) {
    arr.push(count(i));
  }
  function count(n) {
    let t = n & (n - 1);
    //原有数据中已有，+1后并写入暂存；
    if (temp[t] !== undefined) {
      temp[n] = temp[t] + 1
    }
    return temp[n];
  }
  return arr;
};
```



