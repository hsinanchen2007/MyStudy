使用最简单的数学反转方法即可<br>
把不符合条件的先排除

```
var isPalindrome = function(x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false
        console.log(x)
    var result = 0, y = x;
    while (  y != 0) {
        result = result *10 + y % 10;
        y = Math.floor(y/10)
    }
    return result === x
};
```
但是结果不怎么理想哈哈
`
执行用时 : 428 ms, 在Palindrome Number的JavaScript提交中击败了62.65% 的用户
`
`
内存消耗 : 48.3 MB, 在Palindrome Number的JavaScript提交中击败了5.01% 的用户
`