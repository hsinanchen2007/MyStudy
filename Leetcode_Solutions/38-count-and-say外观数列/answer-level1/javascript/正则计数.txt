## 第一版，正则 + 循环
> 60ms,35.2M。
## 思路：先观察规律，显然每一阶数中任意部分的元素一次最多连续不会超过3次，所以任一阶数的组成元素最多只有1、2、3。所以我直接使用正则`/(1+)|(2+)|(3+)/g`来匹配字符串即可
```javascript []
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
  let str = '1';
  for (let i = 0; i < n - 1; i++) {
    str = str.match(/(1+)|(2+)|(3+)/g).reduce((pre, cur) => pre + cur.length + cur[0], '');
  }
  return str;
};
```

## 第二版，正则 + 递归
> 80ms,35.3M。
```javascript []
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n, str = '1') {
  return n > 1 ? countAndSay(n - 1, str.match(/(1+)|(2+)|(3+)/g).reduce((pre, cur) => pre + cur.length + cur[0], '')) : str;
};
```

#### to do 循环计数