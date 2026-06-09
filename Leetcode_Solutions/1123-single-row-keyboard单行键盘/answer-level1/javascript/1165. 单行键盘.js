
### 解题思路

- 生成 ``键位 -> 下标`` 的 ``哈希表``
- 遍历目标 ``字符串``，求当前键位下标与上一个键位下标的值的差
- 累加上面一步得到的值，直至循环结束

### 代码

```javascript
/**
 * @param {string} keyboard
 * @param {string} word
 * @return {number}
 */
var calculateTime = function(keyboard, word) {
    let map = new Map()
    let sum = 0
    let prev = 0
    for (let i = 0; i < keyboard.length; i++) {
        map.set(keyboard.charAt(i), i)
    }
    for (let i = 0; i < word.length; i++) {
        let val = map.get(word.charAt(i))
        sum += Math.abs(prev - val)
        prev = val
    }
    return sum
};
```