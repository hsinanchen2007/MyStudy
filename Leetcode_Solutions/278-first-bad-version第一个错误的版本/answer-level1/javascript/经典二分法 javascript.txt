### 解题思路
此处撰写解题思路

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
        let s = 1, e = n 
        // 处理边界值
        if(isBadVersion(s) ) return s
        while(s +1 < e){
            let m = (s + e)/2 |0;
            if(isBadVersion(m)===false && isBadVersion(m+1)){
                return m+1
            }
            if(isBadVersion(m)===false){
                s = m
            }else{
                e = m
            }
        }
        if(!isBadVersion(s)&&isBadVersion(s+1)){
            return e
        }
        if(!isBadVersion(n)&&isBadVersion(n-1)){
            return s
        }
    };
};
```
循环中止条件为 start + 1 < end，代表差值为1的时候就中止了
同时
start = mid;
end = mid;
这就代表，如果搜寻到start和end相差为1的时候，循环就已经停止，所以需要在循环结束后继续判断
