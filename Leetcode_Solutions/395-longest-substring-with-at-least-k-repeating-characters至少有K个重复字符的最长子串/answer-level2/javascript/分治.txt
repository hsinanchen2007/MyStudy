## 解题思路

- 对特殊情况进行判断，**右指针 - 左指针 + 1 < k**，即不存在改子串，则返回 0
- 定义双指针分别指向字符串首尾
- 统计当前字符串中每一个字符出现的频率，用 Map 进行存储
- 分别移动左右指针，直至左右指针指向的字符次数满足 k 要求，停止移动，得到子串
- 移动左指针，如果指针指向的字符不满足 k 要求，以此时位置为基准，分别递归左右子串，取最大值。如果子串中所有字符都满足要求，则返回**右指针 - 左指针 + 1**

## 代码

```javascript
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestSubstring = function(s, k) {
    const count = (left, right) => {
        if (right - left + 1 < k) return 0

        let times = new Map()
        // 统计各单词出现频率
        for (let i = left; i <= right; i++) {
            if (times.has(str[i])) {
                times.set(str[i], times.get(str[i])+1)
            } else {
                times.set(str[i], 1)
            }
        }

        // 如果该字符出现频次小于K，则不可能出现在结果子串中
        // 分别排除，挪动两个指针
        while(right - left + 1 >= k && times.get(str[left]) < k) {
            ++ left
        }
        while(right - left + 1 >= k && times.get(str[right]) < k) {
            -- right
        }
        // 排除子串中包含符合要求的字符，但是这个长度不会出现对应的频率
        if (right - left + 1 < k) return 0

        // debugger
        // 再对子串进行处理
        for (let i = left; i <= right; i++) {
            // 如果发现不满足的字符出现在子串中，则分别查看改字符左右两边
            if (times.get(str[i]) < k) {
                return Math.max(count(left, i-1), count(i+1, right))
            }
        }

        return right - left + 1
    }

    const str = s.split('')
    return count(0, s.length - 1)
};
```