- 将数字转换为字符串，分割字符串将每一项放到一个数组中，反转数组，再将数组的每一项合并为一个字符串，将得到的结果转换为数值类型；
- 判断如果传入的值与转换得到的值相同，就返回 true，否则返回 false。

```
var isPalindrome = function (x) {
    var reverseNum = (x + "").split("").reverse().join("");
    var result = Number(reverseNum);
    if (x == result) {
        return true
    } else {
        return false
    };
};
console.log(isPalindrome(121)); // true
console.log(isPalindrome(-121)); // false
console.log(isPalindrome(10)); // false
```