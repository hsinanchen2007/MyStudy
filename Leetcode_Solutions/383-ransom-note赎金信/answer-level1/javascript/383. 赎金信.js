// ## 题目剖析🧐

// 题中提到两个字符串，一个赎金信（``ransom``)，另外一个杂志（``magazine``），如果 ``ransom`` 不能由 ``magazine`` 里的字符构成，即 ``magzine`` 包含的字符是 ``ransom`` 的父集则返回 ``true``，否则返回 ``false``

// 这种存在 **对照** 的题目，通常都可以用 ``哈希表`` 来解决。

// ## 梳理逻辑💡

// 我们来简单梳理下这道题的解题思路👇

// ### 思路一

// - 生成 ``magazine`` 的 ``哈希表``，对同个字符进行自增操作
// - 对照 ``ransom`` 字符串，如果在 ``哈希表`` 中找不到或者不够，那么返回 ``false``，否则返回 ``true``

// ### 思路二

// - 遍历 ``magzine`` 字符串
// - 如果有 ``ransom`` 中有字符在 ``magazine`` 中找到，那么在 ``ransom`` 中去除它
// - 如果 ``ransom`` 长度为 ``0`` 那么返回 ``true``，否则返回 ``false``

// ## 示例代码🌰

// ### 解法一
// ```javascript
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    if (ransomNote.length > magazine.length) {
        return false
    }
    let mgMap = new Map()
    for (let mg of magazine) {
        if (mgMap.has(mg)) {
            mgMap.set(mg, mgMap.get(mg) + 1)
        } else {
            mgMap.set(mg, 1)
        }
    }
    for (let note of ransomNote) {
        if (mgMap.has(note)) {
            const val = mgMap.get(note)
            if (val <= 0) {
                return false
            }
            mgMap.set(note, val - 1)
        } else {
            return false
        }
    }
    return true
};
// ```

// ### 解法二

// ```javascript
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    for (let mg of magazine) {
        if (ransomNote.includes(mg)) {
            ransomNote = ransomNote.replace(new RegExp(mg), '')
        }
    }
    return ransomNote.length === 0
};
// ```