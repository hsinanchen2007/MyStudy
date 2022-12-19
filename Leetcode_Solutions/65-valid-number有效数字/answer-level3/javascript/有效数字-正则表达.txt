### 解题思路
 - 正则判断
 - 有e时，就分解递归判断求与
![image.png](https://pic.leetcode-cn.com/fae81c401a7ba70fdc5688c53ad625c7ec8e5aa19bda29b964634ec371d9a39a-image.png)


### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
// 正则表达式加递归解决；
var isNumber = function(s, strict, trim) {
    // 头尾去空格
    s = s.trim();
    // 有效字符e的特殊检测, 含有e就不能再包含空格了
    if(s.includes('e') && !s.includes(' ')) {
        // 只能包含一个e
        if (s.indexOf('e') !== s.lastIndexOf('e')) {
            return false;
        }
        const [first, last] = s.split('e');
        // e的前后必须含有有效数字
        if (first === '' || last === '') {
            return false;
        }
        return isNumber(first) && isNumber(last, true);
    }
    // 这里stict 时用于检测e存在的情况，e后面只能是整数；而常规的则有1.3, .3, 1. 这三种情况
    return strict ? /^[\+,-]?[0-9]+$/.test(s) : /^[\+,-]?(([0-9]+(\.[0-9]*)?)|(\.[0-9]+))$/.test(s);
};
```