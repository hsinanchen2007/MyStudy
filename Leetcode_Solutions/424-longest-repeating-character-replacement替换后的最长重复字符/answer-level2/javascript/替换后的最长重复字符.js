![image.png](https://pic.leetcode-cn.com/3275cadd5ed28f0f22cdd9bd972a2df0a438e14137d0f31a7207aece7e005e5b-image.png)

### 解题思路
- 窗口收缩条件，窗口长度减去段内出现次数最多字母个数小于给定的k
- 哈希表作为窗口记录串内元素个数
- 当不满足窗口扩大条件，左指针右移，还要比较一下ans是不是历史最大

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var characterReplacement = function(s, k) {
    let L = 0, R = 0, window = {}, max = 0, ans = 0
    while(R < s.length){
        let w1 = s[R]
        window[w1] ? window[w1] += 1 : window[w1] = 1
        max = Math.max(max, window[w1])
        if( R - L + 1 - max > k){
            let w2 = s[L]
            window[w2]--
            L++
        }
        ans = Math.max(ans, R - L + 1)
        R++
    }
    return ans
};
```