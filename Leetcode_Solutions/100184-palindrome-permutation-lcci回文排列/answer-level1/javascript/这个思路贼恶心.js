### 解题思路
只要判断每一个字符出现的次数是否为偶数，偶数则从字符串中去除，到最后字符串长度为0或1则是回文排列。
恶心点在于用到正则，再遇到特殊字符串就很恶心了，必须要转换成另一种形式才能比较，于是得转一下unicode再匹配

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var canPermutePalindrome = function(s) {
    //去重
    let index = 0;
    let sArr = [];
    while (index < s.length) {
        sArr.push(s.codePointAt(index));
        index++;
    }

    let arr = [...new Set(sArr)];
    let list = []
    s = sArr.toString()

    for (let item of arr) {
        let reg = new RegExp(item, 'g');
        let matchs = s.match(reg);
        if (matchs.length % 2 !== 0) {
            list.push(item)
        }
    }
    return list.length <= 1
};
```