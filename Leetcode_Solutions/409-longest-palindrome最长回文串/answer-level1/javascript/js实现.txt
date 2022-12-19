## 解法1
### 思路

1. 统计各字符的数量；
2. 回文串长度为各字符的数量的最近偶数位之各（如“a”的数量为9，最近偶数位为8）；
3. 如果maxSize小于字符串长度，说明有字符是奇数个，则maxSize加1，因为回文串中心允许有一个字符中点；

### 代码
```js
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function (s) {
    const words = Array(128).fill(0)
    for (let i = 0; i < s.length; i++) {
        words[s[i].charCodeAt()]++
    }
    let maxSize = 0
    words.forEach(w => {
        maxSize += parseInt(w / 2) * 2
    })
    return maxSize < s.length ? maxSize + 1 : maxSize
};
```

### 复杂度分析
* 时间复杂度：O(n)，两次n的循环
* 空间复杂度：O(n)

## 解法2
### 思路
在解法1的基础上优化掉一层loop

### 代码
```js
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function (s) {
    const words = Array(128).fill(0)
    let index = 0
    let maxSize = 0
    for (let i = 0; i < s.length; i++) {
        index = s[i].charCodeAt()
        words[index]++
        if (words[index] % 2 === 0) maxSize += 2
    }
    return maxSize < s.length ? maxSize + 1 : maxSize
};
```

### 复杂度分析
* 时间复杂度：O(n)
* 空间复杂度：O(n)

## 解法3
### 思路
1. 模拟打牌，成对出现的删除；
2. 最后剩下的牌就是奇数留下的，减去的就是能组成回文串的；
3. 回文串允许串中心字符独立，所以最多能从剩下的字符中取一个放到回文串中；

### 代码
```js
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function (s) {
    const charSet = new Set()
    for (let char of s) {
        charSet.has(char) ? charSet.delete(char) : charSet.add(char)
    }
    const size = charSet.size
    return size ? s.length - size + 1 : s.length
};
```

### 复杂度分析
* 时间复杂度：O(n)
* 空间复杂度：O(n)