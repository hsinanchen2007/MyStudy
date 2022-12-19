### 解题思路
此处撰写解题思路转化成数组排序后重新组装成字符串比较

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length !== t.length) {
        return false;
    }

    return s.split("").sort().join() === t.split("").sort().join();
};
```