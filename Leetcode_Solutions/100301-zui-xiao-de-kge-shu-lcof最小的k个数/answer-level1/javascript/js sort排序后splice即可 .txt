### 解题思路
1.先利用排序sort 
2.直接截取长度即可

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    arr.sort((a,b)=>{return a-b})
    return arr.splice(0,k)
};
```