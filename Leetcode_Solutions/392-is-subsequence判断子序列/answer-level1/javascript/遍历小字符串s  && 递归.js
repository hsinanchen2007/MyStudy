### 解题思路
1、遍历s，在t中寻找s字符第一次出现的位置index，找不到直接返回
找到的话将t的index（包括）之前的字符串移除
![222.png](https://pic.leetcode-cn.com/a8531985480b4b7e1e85772b32fd35c321aad54e3ca5ad01d3b5c8799cb970c7-222.png)
2、递归，执行时间75%


### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    let tmpIndex = -1;
    for(let i = 0;i<s.length;i++){
        tmpIndex = t.indexOf(s[i])
        if(tmpIndex === -1){
            return false
        }
        t = t.slice(tmpIndex+1)
    }
    return true
};
```

```javascript
//递归
var isSubsequence = function(s, t) {
    if(s === '') return true
    const index = t.indexOf(s[0])
    return index === -1?false:isSubsequence(s.slice(1),t.slice(index+1))
};
```