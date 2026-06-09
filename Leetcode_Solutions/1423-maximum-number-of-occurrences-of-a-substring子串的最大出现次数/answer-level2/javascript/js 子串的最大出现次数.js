// 学习了一下[楼上java大佬](https://leetcode-cn.com/problems/maximum-number-of-occurrences-of-a-substring/solution/java-hashmap-by-npe_tle/)的代码 🙇‍♀️，写了一个js版本的，思路参考楼上 java HashMap
// ```
/**
 * @param {string} s
 * @param {number} maxLetters
 * @param {number} minSize
 * @param {number} maxSize
 * @return {number}
 */
var maxFreq = function(s, maxLetters, minSize, maxSize) {
    let count = 0
    const getLetters = (str, maxLetters) => {
        let map = new Map()
        for(let i of str) {
            let value = map.get(i)
            map.set(i, value === undefined ? 1 : ++value)
        }
        return map.size <= maxLetters
    }
    let map = new Map()
    for(let i = 0; i < s.length; i++) {
        let str = s.slice(i, i + minSize)
        if (s.length - i < minSize) {
            break
        }
        let value = map.get(str)
        
        if (getLetters(str, maxLetters)) {
            map.set(str, value === undefined ? 1 : ++value)
        }
    }
    for(let [key, value] of map) {
        if (value > count) {
            count = value
        }
    }
    return count
};
// ```
