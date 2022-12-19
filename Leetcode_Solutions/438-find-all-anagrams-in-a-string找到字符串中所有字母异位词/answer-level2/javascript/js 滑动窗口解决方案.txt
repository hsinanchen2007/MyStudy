### 解题思路
参考 [labuladong 滑动窗口思想](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/)

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
    if (!s || !p) return [];
    let need = {}, window = {}, ans = [];
    [...p].forEach(c => need[c] ? need[c]++ : need[c] = 1);
    let l = 0, r = 0, cnt = 0, nkLen = Object.keys(need).length;
    while (r < s.length) {
        let c1 = s[r];
        if (need[c1]) {
            window[c1] ? window[c1]++ : window[c1] = 1;
            if (window[c1] === need[c1]) cnt++;
        }
        r++;
        while (cnt === nkLen) {
            let c2 = s[l];
            if ((r - l) == p.length) ans.push(l);
            if (need[c2]) {
                window[c2]--;
                if (window[c2] < need[c2]) cnt--;
            }
            l++;
        }
    }
    return ans;
};
```