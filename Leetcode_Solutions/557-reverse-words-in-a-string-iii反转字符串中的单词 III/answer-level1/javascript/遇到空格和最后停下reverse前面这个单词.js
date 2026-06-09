![image.png](https://pic.leetcode-cn.com/5540ec7de8ca1ce297f90b912e2d06ba965af011fcaf0cef58192426101bdb7e-image.png)

思路：
1. 遍历整个字符串
2. 遇到空格或者最后就停下，reverse前面的单词
3. 拼接
```
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let f = 0;
    let t = '';
    for(let i = 0; i < s.length; i++) {
        if(s[i] === ' ') {
           t += reverse(s.slice(f, i)) + ' ';
            f = i + 1;
        }
        if(i === s.length - 1) {
            t += reverse(s.slice(f));
        }
    }
    return t;
};
var reverse = function(s) {
    let t = '';
    for(let j = s.length - 1; j >= 0; j--) {
        t += s[j];
    }
    return t;
}
```
