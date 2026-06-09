### 解题思路
输入:
`["abc", "dda", "bc", "xy", "c"]`
遍历反转字符串得到:
`["cba", "add", "cb", "yx", "c"]`
自然排序:
`["add", "c", "cb", "cba", "yx"]`
过滤头部叠加的字符串(即是下一个字符串从首个字符开始的子组):
`["add", "cba", "yx"]`
计算出结果长度为 `11`

(代码已将过滤和计算结果的步骤写在同一个遍历里)

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
    return words.map(word => {
        return word.split('').reverse().join('')
    }).sort().reduce((result, word, index, arr) => {
        let next = arr[index + 1] || ''
        if (word.length > next.length || next.slice(0, word.length) != word) {
            result += word.length + 1
        }
        return result
    }, 0)
}

```