### 解题思路
i-j左到右，
如果没有重复字符串，则j+1,
如果遇到重复则清除掉i-j存到hashSet中的值，并将i赋值为j

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    var n = s.length;
    var hashSet = new Set();
    var long = 0,
        i = 0,
        j = 0;

    // range[i, j]
    while (i < n && j < n) {
        if (!hashSet.has(s.charAt(j))) {
            hashSet.add(s.charAt(j++));
            long = Math.max(long, j - i);
        } else {
            hashSet.delete(s.charAt(i++));
        }
    }

    return long;
};

```