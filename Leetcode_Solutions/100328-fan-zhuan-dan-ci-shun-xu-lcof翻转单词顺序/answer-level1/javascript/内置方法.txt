### 解题思路
看

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    /**
     * 函数式编程：
     *  1.根据空格转换数组
     *  2.过滤空字符串
     *  3.去掉字符串两端空格，当文本不是字符串时会报错，所以加上call,可以处理不是字符串的对象
     *  4.数组反转
     *  5.根据空格转换成字符串
     */
    const res = s.split(" ")
                .filter(item => Boolean(item))
                .map(item => String.prototype.trim.call(item))
                .reverse()
                .join(" ")
    return res
};
```