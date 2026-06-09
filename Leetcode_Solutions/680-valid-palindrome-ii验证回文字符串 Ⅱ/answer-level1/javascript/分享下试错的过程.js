## 第一版
> 败在了第372个测试用例"eeccccbebaeeabebccceea"
```javascript []
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
  // 错误原因是这里的判断条件不合适，导致了可以删除一个以上数量的字符
  for (let i = 0, j = s.length - 1; i < j && i + j >= s.length - 2; i++, j--) {
    if (s[i] === s[j]) continue;
    if (s[i] === s[j - 1]) j--;
    else if (s[i + 1] === s[j])i++;
    else return false;
  }
  return true;
};
```
## 第二版
> 败在了第414个测试用例"eddboebddcaacddkbebdde"
```javascript []
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
  for (let i = 0, j = s.length - 1; i < j; i++, j--) {
    if (s[i] === s[j]) continue;
    // 这里的判断条件仍然有缺陷，只考虑了右指针删除一个字符情况，而未考虑到左指针删除一个字符的情况
    if (i + j <= s.length - 2) return false; 
    if (s[i] === s[j - 1]) j--;
    else if (s[i + 1] === s[j])i++;
    else return false;
  }
  return true;
};
```
## 第三版
> 败在了第456个测试用例"ebcbbececabbacecbbcbe"
```javascript []
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
  for (let i = 0, j = s.length - 1; i < j; i++, j--) {
    if (s[i] === s[j]) continue;
    if (i + j <= s.length - 2 || i + j >= s.length) return false;
    // 这回错在第一次删除字符时如果删除左或删除右都可以往下走时会仅处理了删除右的情况结果不会变成回文串
    // 然而此时如果删除左的话是可以变成回文串
    if (s[i] === s[j - 1]) j--;
    else if (s[i + 1] === s[j]) i++;
    else return false;
  }
  return true;
};
```
## 第四版
> 92ms,42.3M。成功击败95.76%用户
```javascript []
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s, count = 0) {
  for (let i = 0, j = s.length - 1; i < j; i++, j--) {
    if (s[i] === s[j]) continue;
    if (count > 0) return false;
    // 用递归就方便多了，还可以很好的使用到可删除多个字符的情况
    return validPalindrome(s.slice(i, j), count + 1) || validPalindrome(s.slice(i + 1, j + 1), count + 1);
  }
  return true;
};
```
#### 总结：这种题目还是不容易一次性思考全面，还需要多加练习哦。
