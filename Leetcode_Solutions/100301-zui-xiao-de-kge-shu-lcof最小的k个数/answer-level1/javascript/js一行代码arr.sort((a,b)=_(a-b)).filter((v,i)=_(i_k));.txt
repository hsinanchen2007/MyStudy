### 解题思路
升序排序返回前k个数即可

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    return arr.sort((a,b)=>(a-b)).filter((v,i)=>(i<k));


};
```