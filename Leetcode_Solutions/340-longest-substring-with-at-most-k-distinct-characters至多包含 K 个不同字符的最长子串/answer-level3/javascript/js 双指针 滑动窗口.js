

### [340\. 至多包含 K 个不同字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/)

Difficulty: **困难**


给定一个字符串** _s_** ，找出 **至多 **包含 _k_ 个不同字符的最长子串 **_T_**。

**示例 1:**

```
输入: s = "eceba", k = 2
输出: 3
解释: 则 T 为 "ece"，所以长度为 3。
```

**示例 2:**

```
输入: s = "aa", k = 1
输出: 2
解释: 则 T 为 "aa"，所以长度为 2。
```



#### 解题思路

1. 采用双指针法，用两个指针(l, r)分别记录窗口的左右边界
2. 用 `map` 来存储字符状态，以字符为 `key`，字符出现的次数为 `value`
3. 开始遍历字符串 `s`，并将字符存入 `map` 中，如果 `map` 的键值个数等于 `k`，则说明找到了一个符合要求的子串，子串的左右边界就是 `l` 和 `r`
4. 然后将左边界的值移出窗口，并将左边界 `l++`，再移动右边界 `r++`，直到找到下一个符合要求的子串
5. 记录子串的长度，找出所有符合要求的最长子串，并返回该长度

#### 代码

Language: **JavaScript**

```javascript
​/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var lengthOfLongestSubstringKDistinct = function(s, k) {
    let window = {}, l = 0, r = 0, count = 0, ans = 0;
    while (r < s.length) {
        let c1 = s[r];
        window[c1] ? window[c1]++ : window[c1] = 1;
        r++;
        while (Object.keys(window).length > k) {
            let c2 = s[l];
            window[c2]--;
            if (window[c2] === 0) delete window[c2];
            l++;
        }
        ans = Math.max(ans, r - l);
    }
    return ans;
};
```