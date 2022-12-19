### 解题思路

这题做起来有些难度的，首先对传入参数的字符串考滤的需要全面。我一做的时候就是没考滤完全导致提交几次都错了。
首先我们看下传入的字符串会有哪些情况的。
1. "" 
2. " "
3. "a"
3. "au"
4. "abcabcbb"
5. "bbbbb"
6. "dvdf"

首先处理1，2，3种，小于等于1个字符的，肯定是不会有重复字符的，所以直接返回字符串的长度即可。

余下的我们声明一个 len用来存储最长字符串的长度， 一个lenstr来存储字符串。
把第一字符直接放到lenstr中。我们循环从第二个字符开始。

在循环里，判断下当前的字符是否已经在lenstr字符串里， 如果不在， 字符串lenstr = lenstr + 当前的字符，继续循环
如果已经在lenstr里了，我们把len和当前字符串lenstr长度，较大的那一个重新赋值给len, 使用len能一直保存的是最长字符串的长度。
lenstr合并当前字符串后并从找到重复字符位置+1的地方截取，重新赋给lenstr。保证lenstr里没有重复的字符。

最后返回 len 和lenstr.length中最大的那一个值。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let len = 0; // 用来存储字符串长度
    let lenstr = s[0]; // 存储第一个

    // 如果只有一个，返回1
    if (s.length <= 1) return s.length;

    for (let i = 1; i< s.length; i++) {
        
        if (lenstr.indexOf(s[i]) > -1) {
            // 如果在lenstr 找到了当前的字符， 就说明是有重复的字符
            len = Math.max(len, lenstr.length); // 把len和当前字符串长度的大的那一个重新赋值给len
            lenstr = (lenstr + s[i]).slice(lenstr.indexOf(s[i]) + 1) // 字符串从找到重复的位置+1地方截取
        } else {
            // 没有重复字符，刚直接把当前字符加到lenstr
            lenstr += s[i]
        }
    }
    // 返回lenstr长度和len这两个值的最大的那个
    return Math.max(len, lenstr.length)
};
```