
### [30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)

难度: **困难**


给定一个字符串 **s** 和一些长度相同的单词 **words**找出 **s** 中恰好可以由 **words** 中所有单词串联形成的子串的起始位置。

注意子串要与 **words** 中的单词完全匹配，中间不能有其他字符，但不需要考虑 **words**中单词串联的顺序。



**示例 1：**

```
输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
```

**示例 2：**

```
输入：
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
输出：[]
```



#### Solution

Language: **JavaScript**

### 解法一：暴力求解

**解题思路：**
1. 由于子串不需要考虑 `words` 中单词出现的顺序，并且`words`中可能会出现重复单词，所以不能用 `set` 来存储`words`，我们可以用`map`来存储`words`，把`words`中的单词作为`key`，单词出现的次数作为`value`
2. 循环字符串`s`，然后每次从字符串`s`中截取一段长度为 `words` 单词总长的字符串，然后按照单个`words`单词的长度，对其进行拆分成单词
3. 使用拆分后的单词去`map`中查询，如果存在，则将其 `value - 1`，否则表明当前字符串不符合要求，直接`break`跳出当前循环
4. 内层循环结束后，如果`map`所有的 `value` 都为`0`，则表明当前子字符串符合要求，将其起始索引放入结果集中
5. 最后返回结果集

**代码：**
```javascript
​/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
    if (!words || !words.length) return[];
    let wordLen = words[0].length;
    let allWordsLen = wordLen * words.length;
    let ans = [], wordMap = {};
    for (let w of words) {
        wordMap[w] ? wordMap[w]++ :wordMap[w] = 1
    }
    for (let i = 0; i < s.length - allWordsLen + 1; i++) {
        let wm = Object.assign({}, wordMap);
        for (let j = i; j < i + allWordsLen - wordLen + 1; j += wordLen) {
            let w = s.slice(j, j + wordLen);
            if (wm[w]) {
                wm[w]--
            } else {
                break;
            }
        }
        if (Object.values(wm).every(n => n === 0)) ans.push(i);
    }
    return ans;
};
```

**时间复杂度**：`O(KN)`
`N` 为 `s` 的长度，`K` 为 `words` 一个单词的长度

**空间复杂度**：`O(N + M)`
`N` 为 `s` 的长度，`M` 为 `words` 的长度


#### 解法二：滑动窗口

**解题思路：**
1. 在暴力求解的基础上进一步优化，我使用两个 `map`，`windows` 和 `needs`，`windows`存储`s`的子串，`needs`存储`words`，并且使用两个指针 `l` 和 `r`,表示一个窗口的左右两边的索引
2. 外层循环索引 `i` 从 `0` 开始，并且 `i < oneWordLen` 只用循环一个单词的长度
3. 内层循环从 `i` 开始，`l = r = i`，依次进行截取 `let w = s.slice(i, i + oneWordLen)`，判断截取的单词 `w` 是否存在于存储 `needs` 中，如果不存在，则直接`continue`跳过当前循环
4. 如果存在则将其添加到 `windows` 中，如果 `windows[w] === needs[w]`则将`count++`，表示一个单词已经准备就绪
5. 如果 `count === Object.key(needs).length`，则表示所有的单词都已经准备就绪，由于有可能会出现多个重复的符合要求的单词，所以此时还需要判断 `r - l === words所有单词的长度和`
6. 如果条件成立则表示当前子字符串符合要求，将子字符串的起始索引`l`，放入结果集中 `ans.push(l)`
7. 从窗口的左边截取子字符串 `let w2 = s.slice(l, l + oneWordLen)`，如果 `w2` 存在于 `needs` 中，则`windows[w2]--`，并且如果 `windows[w2] < needs[w2]`，则`count--`
8. 最后返回结果集`ans`

**代码：**
```javascript
/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
    if (!s || !words || !words.length) return [];
    let windows = {}, needs = {}, oneWordLen = words[0].length;
    for (let w of words) {
        needs[w] ? needs[w]++ : needs[w] = 1;
    }
    let l = 0, r = 0, count = 0, needsKeyLen = Object.keys(needs).length, ans = [];
    for (let i = 0; i < oneWordLen; i++) {
        windows = {};
        r = l = i;
        count = 0;
        while (r <= s.length - oneWordLen) {
            let w1 = s.slice(r, r + oneWordLen);
            r += oneWordLen;
            if (!needs[w1]) {
                windows = {};
                l = r;
                count = 0;
                continue;
            }
            windows[w1] ? windows[w1]++ : windows[w1] = 1;
            if (windows[w1] === needs[w1]) count++;
            while (count === needsKeyLen) {
                if (r - l === oneWordLen * words.length) ans.push(l);
                let w2 = s.slice(l, l + oneWordLen);
                l += oneWordLen;
                if (needs[w2]) {
                    windows[w2]--;
                    if (windows[w2] < needs[w2]) count--;
                }
            }
        }
    }
    return ans;
};
```

**时间复杂度**：`O(N)`
外层循环时间复杂度为`O(K)`，`K` 为 `words` 一个单词的长度
内层循环时间复杂度为 `O(2 * N / K)`，即 `l`和`r`从字符串起始索引遍历到结束索引，每次递加`K`
所以，时间复杂度为 `O(K * 2 * N / K) = O(2N) => O(N)`

**空间复杂度**：`O(N + M)`
`N` 为 `s` 的长度，`M` 为 `words` 的长度