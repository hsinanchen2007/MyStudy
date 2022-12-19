### 解题思路
代码的思路比较简单，就是维护一个数组`arr`，对原字符串遍历，判断字符是否在`arr`里面，不在的话就直接`push`进去，再重新判断`max`的大小；在的话就将之前重复`arr`字符之前的项全部去除，再重新`push`进去。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let arr = [];
    let max = 0;
    for(let item of s){
        if(arr.includes(item)){
            let index = arr.indexOf(item);
            arr.splice(0, index + 1);
        }
        arr.push(item);
        max = max > arr.length ? max : arr.length;
    }
    return max;
};
```