### 解题思路

#### 思路一

对于这种 ``字符串`` 类型的题目，通常 ``哈希表`` 都是比较容易想到的解法，通常会出现在这样的题目中：

- 两个 ``字符串`` 比对 / 找不同
- 单个值映射出现的次数（不唯一）

#### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    let sMap = new Map()
    let tMap = new Map()

    // 对字符串 s 做一次 哈希映射
    for (let i = 0; i < s.length; i++) {
        let word = s.charAt(i)
        let val = sMap.get(word)
        if (sMap.has(word)) {
            sMap.set(word, val + 1)
        } else {
            sMap.set(word, 1)
        }
    }
    // 检测字符串 t
    for (let i = 0; i < t.length; i++) {
        let word = t.charAt(i)
        let val = tMap.get(word)
        // 如果字符串 s 里没有这个字母
        // 说明该字母是被添加的字母
        if (!sMap.has(word)) {
            return word
        }
        if (tMap.has(word)) {
            // 如果字符串 s 里的字母数比字符串 t 里的少，
            // 说明该字母是被添加的字母
            if (val + 1 > sMap.get(word)) {
                return word
            } else {
                tMap.set(word, val + 1)
            }
        } else {
            tMap.set(word, 1)
        }
    }
};
```

时间复杂度： $O(n)$
空间复杂度： $O(n)$

#### 思路二

由于每个字母都只对应一个 ``ASCII 码``，所以这道题可以演化成为求 [数组中只出现一次的数字](https://leetcode-cn.com/problems/single-number/)，这里直接用 ``位运算`` 即可。

#### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    let temp = 0
    for (let i = 0; i < s.length; i++) {
        temp ^= s.charCodeAt(i)
    }
    for (let i = 0; i < t.length; i++) {
        temp ^= t.charCodeAt(i)
    }
    return String.fromCharCode(temp)
};
```

时间复杂度： $O(n)$
空间复杂度： $O(1)$

#### 思路三

由上一个思路演化，除了采用 ``位运算``，也可以直接求两个字符串的 ``ASCII 码`` 的差值。

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    let sum = 0
    for (let i = 0; i < t.length; i++) {
        sum += t.charCodeAt(i)
    }
    for (let i = 0; i < s.length; i++) {
        sum -= s.charCodeAt(i)
    }
    return String.fromCharCode(sum)
};
```

时间复杂度： $O(n)$
空间复杂度： $O(1)$