// ## 题目剖析🧐

// 这道题的题意非常简单 —— 求最后一个单词的长度。

// ## 梳理逻辑💡

// 这道题虽然很简单，但是我们依然梳理下逻辑（凑字数）👇

// - 从字符串末尾开始遍历
// - 遇到非空格字符开始计数，直到遇到下一个空格或者字符串遍历结束为止

// 当然，这道题我们也可以用正则来做：

// - 替换首尾空格
// - 按空格切分单词
// - 返回最后一个单词的长度

// ## 示例代码🌰

// 解法1:
// ```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let flag = 0, i = s.length - 1
    
    while (i >= 0) {
        if (s.charAt(i) === ' ') {
            if (flag) {
                return flag
            }
        } else {
            flag++
        }
        i--
    }
    return flag
};
// ```

// - 时间复杂度： ``O(n)``
// - 空间复杂度： ``O(1)``

// 解法二：

// ```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let ans = s.replace(/^\s*|\s*$/g, '').split(/\s+/)
    return ans[ans.length - 1].length
};
// ```