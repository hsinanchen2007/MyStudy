![image.png](https://pic.leetcode-cn.com/1869fc5bbb42aefe6808b3fbce48ecce442a316cf59fd2f9cb897ff7a027ff7d-image.png)

### 解题思路
```js
二分查找：找到并返回 false 后的第一个 true

1.当前的版本是坏的并且他的上一个版本是好的
2.当前的版本是坏的，并且他就是第一个版本
- 满足以上两个条件之一就可以返回这个版本了

- 否则：如果当前版本是坏的，那么他后面的版本一定是坏的，所以向左边半区查找即可，反之，查找右边半区
```

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
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
  
    return function(n) {
      let low = 0,
          high = n,
          ans = null;
      
      while (low <= high) {
        let mid = low + ((high - low) >> 1);
        
        if ((isBadVersion(mid) && !isBadVersion(mid - 1)) || 
           (isBadVersion(mid) && mid === 0)) {
          ans = mid;
          break;
        }
        
        if (isBadVersion(mid)) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      
      return ans;
    };
};
```