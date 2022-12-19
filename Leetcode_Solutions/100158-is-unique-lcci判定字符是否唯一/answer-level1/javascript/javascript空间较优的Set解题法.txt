### 解题思路
此处撰写解题思路

这是一道很简单的题目，
首先： 我们将字符串转换成数组
然后，将数组转换Set，大家都知道Set是不允许重复值的。
当变换前的数组长度和变换后的数组长度相同，代表没有重复数据
结果： 返回true
当长度不一样，那么代表有重复字段被筛选出去了。
结果： 返回false

不足之处，用到了其他数据结构。QAQ
### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    // 切割数组
    const strArr = astr.split('')
    // 转换Set结构
    const strSet = [...new Set(strArr)]
    return strArr.length === strSet.length
};
```