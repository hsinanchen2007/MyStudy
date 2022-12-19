### 解题思路

Javascript 模拟字符串相加，思路：把字符串转换成数组，不同位对齐相加，结果转换成字符串输出

注意点：如果某一位大于10需要进1

### 代码

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
  // 特殊情况：如果一个字符串是0，直接返回另一个字符串
  if (num1 === '0') return num2;
  if (num2 === '0') return num1;
  // 位数对齐，增加前导0
  const maxLen = Math.max(num1.length, num2.length);
  if (num1.length < maxLen) {
    let tmp = maxLen - num1.length;
    while (tmp > 0) {
      num1 = '0' + num1;
      tmp--;
    }
  }
  else if (num2.length < maxLen) {
    let tmp = maxLen - num2.length;
    while (tmp > 0) {
      num2 = '0' + num2;
      tmp--;
    }
  }
  // 将字符串转化成数组
  const arr1 = num1.split('');
  const arr2 = num2.split('');
  // 高位增加一个0（处理加法进1）
  let resultArr = new Array(maxLen + 1).fill(0);
  // 循环增加，如果大于10进1
  for (let i = maxLen - 1; i >= 0; i--) {
    resultArr[i + 1] = resultArr[i + 1] + parseInt(arr1[i]) + parseInt(arr2[i]);
    if (resultArr[i + 1] >= 10) {
      resultArr[i]++;
      resultArr[i + 1] -= 10;
    }
  }
  // 删除可能的前导0
  if (resultArr[0] === 0) {
    resultArr.shift(1);
  }
  // 转化成字符串输出
  return resultArr.join('');
};
```