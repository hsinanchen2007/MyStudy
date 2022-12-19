KMP算法，时间复杂度O(h+n)，参考[阮一峰kmp](http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html)
写substr和暴力搜索，不考虑面试么。
另外更高效的算法，BM算法(O(h))和Sunday，
[BM算法](http://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html)

```js
const strStr = function(haystack, needle) {
    if (needle === "") return 0;
    if (haystack === "") return -1;
    let inc = [];
    // 计算偏移量
    for (let i = 0; i < needle.length; i++) {
        for (let j = 0; j <= i; j++) {
            if (needle[j] !== needle[i - j]) {
                inc[i] = j + 1;
                break;
            }
            if (j === i && needle[j] === needle[i - j]) {
                inc[i] = j + 1;
            }
        }
    }
    let i = 0;
    let l = needle.length
    while (i < haystack.length) {
        for (let j = 0; j < l; j++) {
            if (needle[j] !== haystack[i + j]) {
                i += inc[j];
                break;
            }
            if (j === l - 1 && needle[j] === haystack[i + j]) {
                return i;
            }
        }
    }
    return -1;
};
```