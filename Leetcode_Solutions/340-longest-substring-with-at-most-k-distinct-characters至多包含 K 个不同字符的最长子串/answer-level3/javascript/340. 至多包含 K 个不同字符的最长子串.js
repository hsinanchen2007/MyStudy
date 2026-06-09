// ## 滑动窗口思想
// + 讲解
//   + [滑动窗口11道](https://github.com/Alex660/Algorithms-and-data-structures/blob/master/demos/%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A311%E9%81%93.md)
// + 类似题型
//   + 1、[3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)
//   + 2、[30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)
//   + 3、[76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)
//   + 4、[159. 至多包含两个不同字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/)
//   + 5、[209. 长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)
//   + 6、[239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)
//   + 7、[340. 至多包含 K 个不同字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/)
//   + 8、[438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)
//   + 9、[567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)
//   + 10、[632. 最小区间](https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/)
//   + 11、[727. 最小窗口子序列](https://leetcode-cn.com/problems/minimum-window-subsequence/)
// + 戳看👇
//   + [leetCode所有题解](https://github.com/Alex660/leetcode)
// #### 解法：滑动窗口经典解法
// + [参考解法 - 159.至多包含两个不同字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/solution/159-zhi-duo-bao-han-liang-ge-bu-tong-zi-fu-de-zu-2/)
// ```javascript
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var lengthOfLongestSubstringKDistinct = function(s, k) {
    let n = s.length;
    if(n < k || n === 0) return n;
    let left = 0,right = 0;
    let windows = {};
    let match = 0,maxLen = Number.MIN_SAFE_INTEGER;
    while(right < n){
        let c1 = s[right];
        windows[c1] ? windows[c1]++ : (windows[c1] = 1) && match++;
        right++;
        while(match > k){
            let c2 = s[left];
            if(windows[c2] === 1){
                match--;
            }
            windows[c2]--;
            left++;
        }
        maxLen = Math.max(maxLen,right - left);
    }
    return maxLen;
};
// ```