### 解题思路
**hash表 + 双指针**
1. hash表用于记录目前窗口内 a b c 分别的个数
2. 当每一个字母个数都大于等于1时，为计算总数加 right 指针剩余位数
3. 左指针右移，入仍符合条件，继续叠加
4. 如此类推，最后返回总数

以示例 1 为例
当第一次满足 abc 个数都大于 0，即left指针为0，right指针为2时 => 'abc', 'abca', 'abcab', 'abcabc' 均成立，由此可以统计 count += s.length - right
满足 abc 个数都大于 0，后左节点像右移动，对应移除字母再hash表上减 1 => hash = {a: 0, b:1, c:1}   'bc'
（如果依然成立，即可统计 count += s.length - right, 如示例2中 aaacb(这时候count+= 1) => aacb(再次count+= 1)）
当条件不成立时，右节点向右移动，如此循环，直至right到达最右，且 hash 表永远不满足条件

右指针最多走 n 次，左指针最多走 n - 2次，所以 时间复杂度为 O(n)
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
// 滑动窗口
var numberOfSubstrings = function(s) {
    let hash = {
        a: 0,
        b: 0,
        c: 0
    }
    let arr = s.split('')
    let count = 0
    let left = 0
    let right = 0
    while(right <= s.length - 1) {
        hash[arr[right]] ++

        while(hash['a'] >= 1 && hash['b'] >= 1 && hash['c'] >= 1) {
            count += s.length - right 
            hash[arr[left]] --
            left ++
        }
        right ++
    }
    return count
    
};
```