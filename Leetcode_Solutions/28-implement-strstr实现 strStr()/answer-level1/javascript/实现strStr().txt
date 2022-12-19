### 解题思路
#### 1、sunday解法
用整个整个的匹配思想

### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
// JS实现sunday算法
var strStr = function(haystack, needle) {
    // 边界条件
    if(needle === "") return 0;
    let needLen = needle.length;
    if(needLen > haystack.length) return -1;
    // sunday算法
    for(let i = 0 ; i < haystack.length; i ++) {
        let partten = haystack.substr(i,needLen); // 从i开始截取needLen的长度
        let leftStr = haystack.substring(i); // 一直截取到末尾，如果第二个参数有值，则截取到第二个参数的前一项
        if(partten === needle){
            return i;
        }
        if(leftStr.length < needLen) {
            return -1;
        }
    }
    return -1;
};
```
#### 2、直接用js现有的轮子

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
// JS实现sunday算法
var strStr = function(haystack, needle) {
    return haystack.indexOf(needle)
};
```