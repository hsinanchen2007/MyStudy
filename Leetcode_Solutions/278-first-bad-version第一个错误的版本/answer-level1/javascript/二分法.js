**代码**
```
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
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
      let l = 0, h = n;
      while (l < h) {
        let m = Math.floor(l + (h - l) / 2);
        if (isBadVersion(m)) {
          h = m;
        } else {
          l = m + 1;
        }
      }
      return l;
    };
};
```
