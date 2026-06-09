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
// #### 解法一：滑动窗口经典解法
// + [类似题型 438. 找到字符串中所有字母异位词 - 解法](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/438-zhao-dao-zi-fu-chuan-zhong-suo-you-zi-mu-yi-3/)
//   + 和438题解法几乎一摸一样，只是修改下返回条件即可
// ```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    let left = 0,right = 0;
    let needs = {},windows = {};
    let match = 0;
    for(let i = 0;i < s1.length;i++){
        needs[s1[i]] ? needs[s1[i]]++ : needs[s1[i]] = 1;
    }
    let needsLen = Object.keys(needs).length;
    while(right < s2.length){
        let c1 = s2[right];
        if(needs[c1]){
            windows[c1] ? windows[c1]++ : windows[c1] = 1;
            if(windows[c1] === needs[c1]){
                match++;
            }
        }
        right++;
        while(match === needsLen){
            if(right - left === s1.length){
                return true;
            }
            let c2 = s2[left];
            if(needs[c2]){
                windows[c2]--;
                if(windows[c2] < needs[c2]){
                    match--;
                }
            }
            left++;
        }
    }
    return false;
};
// ```
// #### 解法二：计数 + 滑动窗口
// + [解法参考这里](https://leetcode.com/problems/permutation-in-string/discuss/102588/Java-Solution-Sliding-Window)
// + [经典排序算法讲解 - 计数排序](https://github.com/Alex660/Algorithms-and-data-structures/blob/master/theoreticalKnowledge/BitOperation%E4%BD%8D%E8%BF%90%E7%AE%97%E3%80%81Bloom%20Filter%E5%B8%83%E9%9A%86%E8%BF%87%E6%BB%A4%E5%99%A8%E3%80%81LRU%20Cache%E7%BC%93%E5%AD%98%E3%80%81Sorting%20algorithm%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95.md)
// + 计数用处
//   + 当一个字符从窗口的右侧移动时，对应字符计数减去1。
//   + 当一个字符从窗口左侧移出时，对应字符计数加1。
//   + 因此，一旦我们在映射中看到所有的0，
//     + 即在滑动窗口中s1和子字符串之间的每个字符的数量相等时，就是true.
// ```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    let n1 = s1.length,n2 = s2.length;
    if(n1 > n2) return false;
    let count = new Array(26).fill(0);
    let isAllZero = (count) => {
        return count.every( val => val === 0);
    }
    for(let i = 0;i < n1;i++){
        count[s1[i].charCodeAt() - 97]++;
        count[s2[i].charCodeAt() - 97]--;
    }
    if(isAllZero(count)) return true;
    for(let i = n1;i < n2;i++){
        count[s2[i].charCodeAt() - 97]--;
        count[s2[i - n1].charCodeAt() - 97]++;
        if(isAllZero(count)) return true;
    }
    return false;
};
// ```