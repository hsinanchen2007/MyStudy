### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/a79a51865b4678d6292c98d54264fefbddf43c419006596a7ff53c71b95f3e39-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number}
 */
var findLucky = function(arr) {
    var newarr = [];

    for(var i = 0, len = arr.length; i < len; i++) {
        var val = arr[i];
        newarr[val] = newarr[val] ? newarr[val] + 1 : 1;
    }
    
    var result = -1;
    for(var i = 0, len = newarr.length; i < len; i++) {
        if(newarr[i] && newarr[i] == i && i > result) {
            result = i;
        }
    }

    return result;
};
```