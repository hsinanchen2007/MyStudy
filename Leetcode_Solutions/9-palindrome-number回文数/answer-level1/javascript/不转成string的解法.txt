### 解题思路
先把负数与整十数这绝对不会是互文的情况给排除，个位数都是互文的所以也排除。
剩下的还是用了翻转的思想，只是不转成字符串和数组直接利用reverse方式而已

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
const reverseNum = num => {
  let result = num % 10;
  let numToCut = result;

  while (num >= 10) {
    num = (num - numToCut) / 10;
    numToCut = num % 10;
    result = result * 10 + numToCut;
  }
  return result;
}

const isPalindrome = x => {
    if (x < 0 || x % 10 === 0) {
        return x === 0 || false;
    }
    if (x < 10) {
        return true;
    }

    const reverseNumber = reverseNum(x);
    return x === reverseNumber;
};
```