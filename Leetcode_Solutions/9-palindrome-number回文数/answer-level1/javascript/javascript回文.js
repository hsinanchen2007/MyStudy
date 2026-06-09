### 解题思路
此处撰写解题思路

回文嘛，就是从中间截取然后把后一半翻转和前一段对比是否相同，

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {
    // 其实在这个位置应该把负数排除，也就是说，负数一定不是回文数
    // 转成字符串比较好用
    x = x.toString();
    // 获取一半的长度就行了，奇数向下取整，因为奇数最中间的那个数不需要对比
    var flag = Math.floor(x.length / 2);
    // 创建空数组放比对结果
    var arr = [];
    // 循环比对
    for (var index = 0; index < flag; index++) {
        // 把每一个数字的比对结果放入数组
        // 这里用的下标查找的对应字符进行比对
        arr.push(x.charAt(index) === x.charAt(x.length - 1 - index))
    }
    // 用every方法直接判断是否全部相等并return
    return arr.every(val => val === true)
};
```