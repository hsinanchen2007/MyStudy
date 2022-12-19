### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var countBinarySubstrings = function(s) {
    // // 计算前一个字符连续出现的次数
    // let pre = 0
    // // 计算后一个字符连续出现的次数
    // let cur = 1
    // // 每当 pre >= cur 时，既满足条件一次 count++
    // let count = 0
    // for(let i=1; i<s.length; i++) {
    //     if(s[i] === s[i-1]) {
    //         cur++
    //     } else {
    //     // 当出现不一样的字符时，现任变前任，现任重新计数
    //       pre = cur
    //       cur = 1
    //     }
    //     // 只要  pre >= cur, 即可满足条件一次
    //     if(pre >= cur) {
    //         count++
    //     }
    // }
    // return count

    // let count = 0
    // let cur = 1
    // let arr = []
    // for(let i=1; i<s.length; i++) {
    //     if(s[i] === s[i-1]) {
    //         cur++
    //     } else {
    //         // 最后一次push 没有push进arr
    //         arr.push(cur)
    //         cur = 1
    //     }
    //     // 将最后一个 cur push进 arr
    //     if(i == s.length - 1) {
    //         arr.push(cur)
    //     }
    // }
    // for(let j=1; j<arr.length; j++) {
    //     count += Math.min(arr[j], arr[j-1])
    // }
    // return count
    let pre = 0
    let cur = 1
    let count = 0
    for(let i = 1; i < s.length; i++) {
        if(s[i] === s[i-1]) {
            cur++
        } else {
            pre = cur
            cur = 1
        } 
        if(pre >= cur) {
            count++
        }
    }
    return count
};
```