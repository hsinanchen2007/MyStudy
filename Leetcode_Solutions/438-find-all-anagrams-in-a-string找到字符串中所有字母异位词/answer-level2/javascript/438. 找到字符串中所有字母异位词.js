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
// + [类似解法 76. 最小覆盖子串 - 解法二](https://leetcode-cn.com/problems/minimum-window-substring/solution/76-zui-xiao-fu-gai-zi-chuan-by-alexer-660/)
// ```javascript
/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
    let res = [];
    let left = 0,right = 0;
    let needs = {},windows = {};
    let match = 0;
    for(let i = 0;i < p.length;i++){
        needs[p[i]] ? needs[p[i]]++ : needs[p[i]] = 1;
    }
    let needsLen = Object.keys(needs).length;
    while(right < s.length){
        let c1 = s[right];
        if(needs[c1]){
            windows[c1] ? windows[c1]++ : windows[c1] = 1;
            if(windows[c1] === needs[c1]){
                match++;
            }
        }
        right++;
        while(match === needsLen){
            if(right - left === p.length){
                res.push(left);
            }
            let c2 = s[left];
            if(needs[c2]){
                windows[c2]--;
                if(windows[c2] < needs[c2]){
                    match--;
                }
            }
            left++;
        }
    }
    return res;
};
// ```