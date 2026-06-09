### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    if(!S.length) return ''
    let s = S.split(''), res = '', current = s[0],currentNums = 1;
    for(let i = 1; i < s.length; i++) {
        if(current == s[i]) {
            currentNums++
        } else {
            res += current + currentNums.toString()
            current = s[i]
            currentNums = 1
        }
    }
    res += current + currentNums.toString()
    return S.length > res.length ? res : S

};
```

思路大概就是：
    首先用一个变量表示当前变量，用一个数字表示当前的变量有多少个连续相等的值，如果出现不相等的情况，把当前表示的变量放在一个字符串中并加上当前变量连续出现的个数，然后在重新赋值变量以及变量的个数，
    其次是最后一个元素在循环时没有加上，需要单独处理
    最后比较结果的长度与原始值的长度，返回正确的结果