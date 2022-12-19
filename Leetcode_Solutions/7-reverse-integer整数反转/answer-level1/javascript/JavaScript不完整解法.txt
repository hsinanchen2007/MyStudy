### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    <!-- 判断是否为正数 -->
    var TGA = x < 0 ? true : false
    <!-- 使用转为正数的参数分割成数组,反转,转字符串 -->
    var num = ((TGA ? -x : x)).toString().split('').reverse().join('')
    // 前面转为了正数,现在转回来
    num = TGA ? -num : num
    <!-- 判断取值区间 -->
    var res = num < Math.pow(-2, 31) ||  num > (Math.pow(2, 31)-1);
    <!-- 去掉前面的0 -->
    return ~~(res ? 0 : num)
};
```