### 解题思路
起始就是二分法解题

### 代码

```javascript
/**
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function (isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function (n) {
        let left = 1;
        let right = n;
        while (left < right) {
            const middle = Math.floor((right + left) / 2);
            if (isBadVersion(middle)) {
                // 第一个版本号小于等于middle
                right = middle;
            } else {
                // 第一个版本号大于middle
                left = middle + 1;
            }
        }
        return left;
    };
};
```