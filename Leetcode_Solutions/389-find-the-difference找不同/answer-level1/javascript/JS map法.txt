我个人比较喜欢用map法来解决很多遍历的算法问题。
优点是时间复杂度必然是O(n), 缺点是由于v8引擎内联缓存的对象处理方式，不断新加属性效率不高。

直接上代码：
执行用时:72 ms,在所有 JavaScript 提交中击败了98.21%的用户
内存消耗:36 MB,在所有 JavaScript 提交中击败了51.09%的用户
···
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    let a = {};
    for(let item of s) {
        if(!a[item]) {
            a[item] = 1;
        } else {
            a[item]++;
        }
    }
    for(let item of t) {
        if(!a[item]) {
            a[item] = 1;
        } else {
            a[item]++;
        }
    }
    for(let item in a) {
        if(a[item] % 2 != 0) {
            return item;
        }
    }
};
···