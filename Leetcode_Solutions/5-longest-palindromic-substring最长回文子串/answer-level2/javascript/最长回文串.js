
### 一、暴力法
遍历出所有的可能值，会超时
```javascript
 /**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if(!s || s.length < 2) return s;
    let cur = '';
    let max = '';
    for(let i = 0; i < s.length; i++) {
        for(let j = 0; j< s.length; j++) {
            let str = s.substr(i,j+1);
            if(isPalindrome(str) && str.length > max.length) max = str
        }
    }
    return max;
};
const isPalindrome = function(s) {
    let l = 0;
    let r = s.length -1;
    while(l < r) {
        if(s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
```
时间复杂度: O(N^3)
空间复杂度: 0(1)
### 二、动态规划
- 确定dp[i][j]是否是回文数，只需要dp[i+1][j-1]是回文数并且s[i] == s[j]即可。
- 但是长度为0或1的回文传需要特殊处理，即j-i < 2;
- 因为知道dp[i]需要先知道dp[i+1],所以i需要从大到小开始遍历
- 因为知道dp[j]需要先知道dp[j-1],所以j需要从小到大开始遍历


##### 即: dp[i][j] = s[i] == s[j] && ( dp[i+1][j-1] || j - i < 2)

```javascript
 /**
 * @param {string} s
 * @return {string}
 */
// 扩展中心
var longestPalindrome = function(s) {
   let ans = '';
    let n = s.length;
    let dp = Array.from(new Array(n), () => new Array().fill(0));
    for(let i = n-1; i >=0; i--) {
        for(let j = i; j < n; j++) {
            dp[i][j] = s[i] === s[j] && ( j - i < 2 || dp[i+1][j-1])
            if(dp[i][j] && j - i + 1 > ans.length) {
                ans = s.substr(i,j - i + 1);
            }
        }
    }
    return ans;
}
```
时间复杂度: O(N^2)
空间复杂度: 0(N^2)

### 三、扩展中心
```javascript
 /**
 * @param {string} s
 * @return {string}
 */
// 扩展中心
var longestPalindrome = function(s) {
   if(!s || s.length < 2) return s;
   let start = 0; 
   let end = 0;
   for(let i = 0; i < s.length; i++) {
       let len1 = expandCenter(s,i,i); // 中心点位奇数 比如: aabaa
       let len2 = expandCenter(s,i,i+1); // 中心在偶数 比如: aabbcc
       let len = Math.max(len1,len2);
       if(len > end - start) {
           start = i - Math.floor((len-1)/2);
           end = i + Math.floor(len/2);
       }
   }
   return s.substring(start,end+1);
};
const expandCenter = function(s,l,r) {
    while(l>=0 && r < s.length && s[l] === s[r]) {
        l--;
        r++;
    }
    return r - l -1;
}
```
时间复杂度: O(N)
空间复杂度: 0(1)