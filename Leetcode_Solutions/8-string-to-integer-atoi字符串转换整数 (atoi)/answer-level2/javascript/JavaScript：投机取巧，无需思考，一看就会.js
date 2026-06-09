### 题意分析
官方的主要规则可以概况为：
- 无视开头空格
- 返回有符号整数
- 无视整数部分后的字符
- 范围在`32`位内（含）
- 其他情况返回`0`

各位JSer，你品，你细品，这个转换规则，是不是很眼熟？

谜底揭晓，它就是JavaScript世界中的`parseInt()`这一API的转换规则。

### 逻辑梳理
现在来简要阐述下`parseInt()`的转换规则，关于这个API的具体描述，可以查看MDN上的这篇[文档](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/parseInt)。

`parseInt(string, radix)`：
- `string`：要被解析的值。如果参数不是一个字符串，则将其转换为字符串。字符串开头的空白符将会被忽略。
- `radix`（可选）：需要转换的进制，介于 `2` 到 `36`。
- 返回值： 如果被解析参数的第一个字符无法被转化成数值类型，则返回`NaN`。

对比下题意，发现
- 无视开头空格（满足）
- 返回有符号整数（满足）
- 无视整数部分后的字符（满足）
- 范围在`32`位内（含）（**不满足**）
- 其他情况返回`0`（**不满足**）

那么只要有针对性的处理下不满足的条件即可。

##### 范围在32位内（含）

只需简单地将API转换后的值与临界值进行对比就行。
```
if (number < Math.pow(-2, 31) || number > Math.pow(2, 31) - 1) {
    return number < Math.pow(-2, 31) ? Math.pow(-2, 31) : Math.pow(2, 31) - 1;
}
```
##### 其他情况返回0
很显然，API的返回值如果是`NaN`，则说明无法正常转换，所以只需将返回值和`NaN`进行比较即可。

注意，`NaN`和`NaN`并不全等，所以各位JSer不能使用全等操作符（`===`），而该使用`isNaN()`函数来比较。

```
if(isNaN(number)) {
    return 0;
} 
```

##### 小细节
在使用`parseInt(string, radix)`这一API时，如果不传入`radix`参数，会有两种特殊情况：
- 如果字符串 `string` 以"0x"或者"0X"开头, 则基数是`16` (**16进制**).
- 如果字符串 `string` 以"0"开头, 基数是`8`（**八进制**）或者`10`（**十进制**），那么具体是哪个基数，取决与ECMAScript的版本。

所以，通常建议在使用`parseInt()`这一API时，都明确给出期望的进制数，这是一个良好的编程习惯。

### 代码实现
以下是具体的代码实现：
```
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    const number = parseInt(str, 10);

    if(isNaN(number)) {
        return 0;
    } else if (number < Math.pow(-2, 31) || number > Math.pow(2, 31) - 1) {
        return number < Math.pow(-2, 31) ? Math.pow(-2, 31) : Math.pow(2, 31) - 1;
    } else {
        return number;
    }
};
```
### 结尾语
在作者写完这篇题解的同一天里，又拜读了LeetCode官方的[解题思路](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/)——“自动机”，感觉收益匪浅。

个人收获的同时，也想将其思路分享给大家，所以又动手写了一篇关于“自动机”思路的题解。

如果你对“自动机”的解法有兴趣，可以移步[这里](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/javascriptzi-dong-ji-guan-fang-ti-jie-de-xiang-xi-/)查看。

相信我，“自动机”的解法，一定会打开你另一个思路的大门~
