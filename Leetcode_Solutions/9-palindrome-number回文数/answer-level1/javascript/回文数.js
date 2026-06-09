**法一：**

转化成字符串，比较字符串首尾是否一样

```js
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    var StrX = x.toString();
    var len = StrX.length;
    var flag;
    for(let i = 0; i <= Math.floor(len/2); i++) {
        if(StrX[i] === StrX[len-i-1]) {
            flag = true
        } else {
            flag = false
            return flag
        }   
    }
    return flag;
};

var x = -132231;

console.log(isPalindrome(x))
```

**法二：利用数组反转,比较慢，不建议**

```js
var isPalindrome2 = function(x) {
    var StrX = x.toString();
    var flag;
    if (x < 0) {
        flag = false;
        return flag;
    }

    var reverseStrX = StrX.split('').reverse().join('');
    
    if(StrX === reverseStrX) {
        flag = true
    } else {
        flag = false
    }
    return flag;
};

console.log(isPalindrome2(x))
```

**法三：不利用字符串，待补充。。。**