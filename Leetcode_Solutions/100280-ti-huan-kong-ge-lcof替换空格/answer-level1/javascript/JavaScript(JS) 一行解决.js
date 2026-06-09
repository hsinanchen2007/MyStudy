### 解题思路
JavaScript 的数组本质上是链表，所以不用考虑数组扩容的问题。
先将字符串用 split 分割(空格作为分隔符，该方法返回一个数组)，然后用数组的 join 方法(%20作为连接符，该方法返回数组元素连接后的字符串)。

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function(s) {
    return s.split(' ').join('%20')
};
```
![搜索框传播样式-标准色版.png](https://pic.leetcode-cn.com/5b693dce2ea930fe7d095fbb126cc9e8b0d109de3e59c4f09c898d62a09d7a9b-%E6%90%9C%E7%B4%A2%E6%A1%86%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
