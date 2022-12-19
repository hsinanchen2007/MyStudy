/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if (haystack.includes(needle)) {
        // 包含
        const stack = needle ?  haystack.split(needle) : []
        return stack.length > 0 ? stack[0].length : 0
    } else {
        // 不包含直接-1
        return -1
    }
};