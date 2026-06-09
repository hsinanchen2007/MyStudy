```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    // '' 边界判断
    const needleLen = needle.length
    if (needleLen === 0) return 0

    // 边界判断
    const haystackLen = haystack.length
    if (needleLen > haystackLen) return -1

    // 初始化偏移量
    function initailOffsetMap () {
        const offsetMap = {}
        for (let i = 0; i < needleLen; i++) {
            offsetMap[needle[i]] = needleLen - i
        }
        return s => offsetMap[s] || needleLen
    }
    const getOffset = initailOffsetMap()

    // 从右开始匹配
    let i = 0
    while (i <= haystackLen - needleLen) {
        // 模式串匹配
        let temp = 0
        for (let j = 0; j < needleLen; j++) {
            if (haystack[i + j] === needle[j]) temp++
            else break
        }

        if (temp === needleLen) return i
        // 按偏移量跳过
        else i += getOffset(haystack[i + needleLen])
    }
    return -1
};
```