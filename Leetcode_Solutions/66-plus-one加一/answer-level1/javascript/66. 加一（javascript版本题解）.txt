# 方法1： 大数相加的简化
由题意很容易的看出来，该题是大数相加的简化版本。
首先，高位数存放于数组头部，因此需要考虑首位溢出的情况。
最开始想法就是使用一个变量保存进位carry。

```javascript
var plusOne = function(digits) {
    let carry = 1;
    for(let i = digits.length; i > 0; i--) {
        let temp = parseInt((digits[i - 1] + carry) / 10);
        digits[i - 1] = (digits[i - 1] + carry) % 10;
        carry = temp;
    }
    if(carry === 1) digits.unshift(carry);
    return digits;
};
```
最好时间复杂度和最差时间复杂度为O(n).
空间复杂度为O(n).

# 方法二： 优化版本
我们将问题简化为第i位(0 <= i < n)加一或加0。
而加一的结果分为两种情况:
- 加一后需要进位
- 加一后不需要进位
对于第二种情况，我们直接返回digits就可以。
对于第一种情况，我们将指针移到前面一位。继续同样处理。

而边界情况即，首位也产生进位，首位产生进位只会是999....9999这种情况，我们也很容易得出结果。
```javascript
var plusOne = function(digits) {
    for(let i = digits.length; i > 0; i--) {
        digits[i-1]++;
        if(digits[i-1] !== 10) return digits;
        else digits[i-1] = 0;
    }
    return [1].concat(Array(digits.length).fill(0));
};
```