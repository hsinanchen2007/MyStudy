#### 解法：双指针 + 判断回文
+ 判断回文数
  + [9. 回文数](https://leetcode-cn.com/problems/palindrome-number/solution/9-hui-wen-shu-jiang-ti-jie-fu-zhi-dao-liu-lan-qi-k/)
+ 双指针
  + 当s[left] != s[right]
    + s[left+1,right] || s[left,right-1]
    + 有一个为真
      + 说明需要删除一个多余的字符，符合
    + 均为真
      + 说明字符串本身为合法的回文串
    + 均为假
      + 说明至少需要删除一个以上的字符，不合题意
```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
    let n = s.length;
    if(n < 2){
        return s;
    }
    let isPalindrome = (left,right)=> {
        while(left < right){
            if(s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
    for(let i = 0;i < n;i++){
        if(s[i] != s[n-i-1]){
            return isPalindrome(i+1,n-i-1) || isPalindrome(i,n-1-i-1);
        }
    }
    return true;
};
```