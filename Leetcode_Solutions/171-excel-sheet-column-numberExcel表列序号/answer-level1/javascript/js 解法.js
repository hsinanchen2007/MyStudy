执行用时 84ms，击败97%
![image.png](https://pic.leetcode-cn.com/7ec5643ad01dddaefb01f44551ea918c85fcc480cc52df04fe18c2b15302a70f-image.png)
```
/**
 * @param {string} s
 * @return {number}
 */
var titleToNumber = function(s) {
    const map = ['', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'];
    var res = 0;
    var len = s.length;
    for(let c of s) {
        if(len > 1) {
            res += map.indexOf(c) * Math.pow(26, len - 1);
            len--;
        } else {
            res += map.indexOf(c);
        }
    }
    return res;
};
```