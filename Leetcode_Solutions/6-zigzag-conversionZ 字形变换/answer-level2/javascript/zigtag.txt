官方题解第一种方法没想到，就是老老实实的找规律
总的来说就是找每一行的元素和字符串元素下标之间的关系
1. 不考虑第一行和最后一行的情况下，对每行中元素下标分了奇偶考虑
- 奇数下标之间下标之差为：`(numRows - 1) * 2`
- 偶数下标之间差同样为`((numRows - 1) * 2))`
可以认为奇数/偶数下标都是过一个行数周期再到达下一个对应的奇数/偶数下标
而偶数下标第一个值为行数 `row`, 奇数下标第一个值为 `i + (numRows  - 1 - i) * 2 `
2. 第一行和最后一行与中间行的区别在于二者都在拐点上， 不用在像中间行那样区分奇偶，直接当作偶数下标处理即可

代码如下
```
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
  if(numRows === 1) { //只有一行直接返回
      return s;
  }
  let convertString = '';
  const {length} = s;
  for(let i = 0; i < numRows; i++) {
    for (let j = 0; ; j++) {
      let index = -1;
      if (j % 2 === 0) { //偶数下标获取 index
        index = i + (numRows - 1) * j;
      } else if (j % 2 !== 0 && i !==0 && i !== numRows - 1) { //奇数下标获取 index, 注意第一行和最后一行已经在偶数下标中计算过了，所以去掉
        index = i + (numRows  - 1 - i) * 2 + (numRows - 1) * (j - 1);
      }
      if (index >= length) {
        break;
      } else if (index != -1) {
        convertString += s[index];
      }
    }
  }
  return convertString;
};
```

