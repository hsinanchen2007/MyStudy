### 解题思路
一开始自己想的是暴力解法，看了官方题解用set与滑动窗口做了版本。
参考另一位的解法，又把set，has换成了队列，indexOf

### 代码

```javascript

/**
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let j = 0;
    let len = s.length;
    let test = [];
    let max = 0;
    
    while(j < len) {
        //是否包含
        if(test.indexOf(s.charAt(j)) !== -1) {
            test.shift();
        } else {
            test.push(s.charAt(j));
            max = Math.max(max, test.length);
            j++
        }
    }

    return max;
};
```