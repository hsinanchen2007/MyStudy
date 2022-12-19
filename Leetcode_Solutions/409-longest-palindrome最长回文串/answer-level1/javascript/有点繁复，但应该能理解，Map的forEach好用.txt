### 解题思路
![image.png](https://pic.leetcode-cn.com/1eb7fa1855ea9719c6d5c758146ce3582fea2a933f2305a2c210b450c7dd909b-image.png)

遍历字符串，收集每个字母出现的次数，偶数的话，全部累加，**若有**奇数的话，奇数全部累加后减去“奇数的个数”再加1.

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function (s) {
    // return the longest odd number plus all even numbers
    let len = s.length,
        m = new Map(),
        oddAll = 0,
        cnt = 0,
        oddCnt = 0;
        ret = 0;

    if (len === 0) return 0;

    for (let i in s) {
        if (m.has(s[i])) {
            cnt = m.get(s[i]) + 1;
            m.set(s[i], cnt);
        } else {
            m.set(s[i], 1);
        }
    }

    const getEvenOdd = (val, idx, map) => {
        if (val % 2 === 0) {
            // console.log(`${idx}->${val} is even number`);
            ret += val;
        } else {
            // console.log(`${idx}->${val} is odd number`);
                oddCnt ++;
                oddAll += val;
        }
    }

    m.forEach(getEvenOdd);
    if (oddCnt != 0) ret += (oddAll - oddCnt + 1);
    return ret;

};
```