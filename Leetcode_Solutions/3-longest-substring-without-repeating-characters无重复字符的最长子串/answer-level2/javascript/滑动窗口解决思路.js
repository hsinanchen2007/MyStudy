### 解题思路
跟[滑动窗口的最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)的思路很相像，不过会简单很多。

声明一个队列`temp`在`javascript`里面可以视为一个字符串，窗口的左侧从第一个字符开始，依次拓展窗口的右侧，直到遇到与队列内部相等的字符时，依次出队，也就是把窗口的左侧往右边移动直到该字符唯一，继续遍历接下来的字符。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if (s.length <= 1) return s.length
    var max = 0
    var temp = s[0]
    for (var i = 1; i < s.length; i++) {
        var value = s[i]
        while (temp.indexOf(value) > -1) {
            // 出队
            temp = temp.slice(1, temp.length)
        }
        temp += value
        max = Math.max(max, temp.length)
    }
    return max
};

```