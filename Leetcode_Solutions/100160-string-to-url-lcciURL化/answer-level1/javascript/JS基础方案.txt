### 解题思路
思来想去没有想到特别的方案，那就用基础方案解决问题先
1. 纯空字符串判定，使用trim函数去除首尾空格
2. 非纯空字符串，则做以下处理
    1. 去除首尾空格，获取该字符trimS
    2. 获取第一个非空字符下标，即是首部长度index
    3. 利用trimS的长度与index，计算出尾部长度
    4. 利用空格转换函数拼接结果

### 代码

```javascript
/**
 * @param {string} S
 * @param {number} length
 * @return {string}
 */
var replaceSpaces = function(S, length) {
    let trimS = S.trim();
    const transSpace = size => Array.from(Array(size), item => item = '%20').join('');

    //纯空字符
    if (!trimS) {
        return transSpace(length)
    }

    //获取第一个字母的下标
    let firstChar = trimS.charAt(0);
    let index = S.indexOf(firstChar);
    let lastSize = length - (trimS.length + index);

    let front = transSpace(index)
    let end = transSpace(lastSize)
    return front + encodeURIComponent(trimS) + end;
};
```