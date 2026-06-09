思想：
- 1、因为不区分大小写，所以先统一转化为大写或者小写。
- 2、然后用正则表达式过滤掉非数字或者字母的字符。
- 3、判断是否回文

```js
var isPalindrome = function(s) {
    if(s.length === 0)
        return true;
    let toUpper = s.toUpperCase().replace(/[^A-Za-z0-9]/g, "");  // 转换为大写用正则过滤掉非字母或者数字的字符
    let len = toUpper.length;
    for(let i = 0; i < len / 2; ++i) {
        if(toUpper[i] !== toUpper[len - i - 1])     // 判断是否回文
            return false;
    }
    return true;
};
```

![微信图片_20200116205718.png](https://pic.leetcode-cn.com/f3154b7e40dfabfc0231ba01f355eda9242ca8a924ce784f14ed3cc2726cf517-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200116205718.png)
