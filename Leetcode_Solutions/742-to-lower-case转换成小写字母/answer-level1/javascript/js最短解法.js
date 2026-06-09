### 解题思路
看了所有的js题解都比我复杂一丢就放心了，在不用函数库偷工减料的情况下尽量对得住简单。
js的字符是可以跟c/c++一样利用比较符的，所以这里不用charCodeAt。
（内置sort就用了原生这点排序字母表，甚至不用像数字那样a-b修正。）
js这里对字用了隐式转换,所以不能str+32。

### 代码

```javascript
/**
 * @param {string} str
 * @return {string}
 */
toLowerCase = function(str) {
    let res = ''
    for(let i=0; i<str.length; i++){
        res += str[i]<'a' && str[i] >= 'A' ? String.fromCharCode(str[i].charCodeAt()+32) : str[i]
    }
    return res
};
```