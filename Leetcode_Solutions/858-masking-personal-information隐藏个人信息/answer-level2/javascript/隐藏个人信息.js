### 解题思路

首先通过是否有 `@` 去判断是邮箱还是电话号码：

1. 邮箱
   * 通过 `toLowerCase()` 转小写；
   * 获取第一个 `name`，处理成要求的内容。

2. 电话号码
   * 把没用的字符去掉；
   * 获取到后四位数用于之后的字符拼接；
   * 根据字符长度去添加不同数量的 `*`。

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var maskPII = function(S) {
     if(S.match('@')){
        S = S.toLowerCase();
        const reg = /^[a-z]+[^@]/g;
        let name = S.match(reg)[0].split('');
        name = [name[0],'*','*','*','*','*',name[name.length - 1]].join('');
        S = S.replace(reg,name);
        return S;
    }
    S = S.replace(/\(|\)|\s|\-|\+/g,'');
    const { length } = S;
    let lastFour = S.slice(-4);
    let basicStr = `***-***-${lastFour}`;
    let remainder = length % 10;
    if(!remainder) return basicStr;
    let str = '+'.padEnd(remainder+1,'*');
    return `${str}-${basicStr}`
};
```