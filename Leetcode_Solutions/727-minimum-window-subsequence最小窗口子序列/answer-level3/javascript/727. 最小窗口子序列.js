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
// #### 解法：滑动窗口解法
// + 思路
//   + 此题 和 [76题 - 解法二](https://leetcode-cn.com/problems/minimum-window-substring/solution/76-zui-xiao-fu-gai-zi-chuan-by-alexer-660/)几乎一摸一样
//     + 之所以写法不同，是因为和上题的一点区别
//       + 76 题 算出的结果可以不按照模式串中出现的字符顺序出现
//       + 而本题必须按照模式串T中所有字符出现的位置相同
//   + 因此要减枝和优化，直接看代码吧
// + ![截屏2020-02-09上午10.12.33.png](https://pic.leetcode-cn.com/9a2a2e6307fa3205e0f3d3c7ed5805b579cfc30dd0475f6f7155fdd33a33556b-%E6%88%AA%E5%B1%8F2020-02-09%E4%B8%8A%E5%8D%8810.12.33.png)
// ```javascript
/**
 * @param {string} S
 * @param {string} T
 * @return {string}
 */
var minWindow = function(S, T) {
    if(S === T) return S;
    let start = 0;
    let end = S.length - 1;
    let s = 0,t = 0;
    while(s < S.length){
        if(S[s] === T[t]){
            t++;
        }
        if(t === T.length){
            let right = s;
            t--;
            while(t >= 0){
                if(S[s] === T[t]){
                    t--;
                }
                s--;
            }
            s++;
            if(right - s + 1 < end - start + 1){
                start = s;
                end = right;
            }
            t = 0;
        }
        s++;
    }
    return end -start + 1 === S.length ? "" : S.substr(start,end - start + 1);
};
// ```