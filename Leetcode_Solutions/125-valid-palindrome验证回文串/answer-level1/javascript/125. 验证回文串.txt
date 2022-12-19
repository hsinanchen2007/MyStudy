#### 解法一：调用函数懒蛋法
```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let strArr = s.replace(/[^0-9a-zA-Z]/g,"").toLowerCase().split('');
    return strArr.join('') == strArr.reverse().join('');
};
```
#### 解法二：格式化 + 双指针夹逼
```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    s = s.replace(/[^0-9a-zA-Z]/g,'').toLowerCase();
    let n = s.length;
    let left = 0;
    let right = n-1;
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
};
```