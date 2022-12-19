### 解题思路
最简单的写法，使用js内置api把字符转转化为数组，然后暴力循环判断是否有相等的值就行了。时间复杂度O(1)，空间复杂度O(n2)


### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    var arr = astr.split('');
    for(let i = 0; i < arr.length; i++) {
        for(let j = i + 1; j < arr.length; j++) {
            if(arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
};
```