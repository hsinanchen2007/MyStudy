### 解题思路
创建一个a为set结构数组（成员唯一），
用for of遍历字符串，
循环判断a中是否有当前元素，有则删除，无则添加，
如果为回文串，那么a最后的长度应小于或等于1。
注：当前题目尚未明确字母大小写、字符与空格等条件，暂不考虑;。

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var canPermutePalindrome = function(s) {
    let a=new Set();
    for(let i of s){
        a.has(i)?a.delete(i):a.add(i)
    }
    return a.size<=1
};
```