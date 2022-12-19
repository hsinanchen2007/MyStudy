- 思想就是拿第一和最后一个元素交换。
```js
var reverseString = function(s) {
    let len = s.length;
    for(let i = 0; i < len / 2; ++i) {
        let temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i -1] = temp;
    }
    return s;
};
```
![微信图片_20200114110650.png](https://pic.leetcode-cn.com/638866cdf1c501bb9ae554af430bdfb55075ad08a7075d06106cf14e7a0a67aa-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200114110650.png)
