```
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    var res = 0,
        i = 0;
    var temp = [];
    while(i < s.length) {
        if(temp.indexOf(s[i]) === -1) {
            temp.push(s[i]);
        } else {
            temp.shift();
            continue;
        }
        res = Math.max(res, temp.length);
        i++;
    }
    return res;
};
```
![image.png](https://pic.leetcode-cn.com/cfff3bdc6491c732526bbc05932976cbc202220279fb9e6b1213ea0f72af5885-image.png)
