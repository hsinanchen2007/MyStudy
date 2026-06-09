```
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 * 同66有BigInt问题
 * 思路：两个数直接相加，倒序开始逢2当前为0，下一项加1
 * 例如1010+1011=2021，倒序为1202，其中逢2进1，当前位置-2，第一次1012，第二次10101
 * 注意：下一项可能不存在需要单独判断
 */
var addBinary = function(a, b) {
  // 两个数相加
  // 获取倒序后的数组
  let arr = (BigInt(a) + BigInt(b))
    .toString()
    .split('')
    .reverse();
  for (let i = 0; i < arr.length; i++) {
    // 若当前位数>1，也就是等于2时
    if (arr[i] > 1) {
      // 当前位置-2
      arr[i] = BigInt(arr[i]) - 2n;
      // 判断有没有arr[i + 1]，在最后一项可能没有i+1
      if (arr[i + 1]) {
        // 下一项+1
        arr[i + 1] = BigInt(arr[i + 1]) + 1n;
      } else {
        // 没有最后一位时直接push(1)
        arr.push(1);
      }
    }
  }
  return arr.reverse().join('');
};
console.log(addBinary('1010', '1011'));
```