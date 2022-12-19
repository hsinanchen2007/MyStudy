![image.png](https://pic.leetcode-cn.com/7b4cb6cc103f67229b976fcfacfe2c9519dae765bb59e8f47e23edb69cc3f3bf-image.png)
先要分析：
        1：子串是连续的，我先是想到动态规划，但还是套不上去。
        2：连续子串，就和滑动的窗口很符合了，如果 你会滑动窗口 应该也是顺利解出
        3：实在没办法了，多出一个最多是N的空间的arr数组，但是你遇到重复的需要丢弃一部分arr[0，重复位置的]。
    4：其实这个时候应该想到用hash表，代替查询数组了，
```
var lengthOfLongestSubstring = function (s) {
    if (s.length === 0) return 0
    let nums = [s[0]];
    let res = 1;
    for (let i = 1; i < s.length; i++) {
        let index = nums.indexOf(s[i]);
        if (index < 0) {
            nums.push(s[i]);
        } else {
            res = res > nums.length ? res : nums.length;
            nums.splice(0, index + 1);
            nums.push(s[i]);
        }
    }
    return res > nums.length ? res : nums.length;
};
```
