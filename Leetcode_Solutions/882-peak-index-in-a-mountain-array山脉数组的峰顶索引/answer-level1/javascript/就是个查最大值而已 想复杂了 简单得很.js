### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var peakIndexInMountainArray = function (A) {
        let index=0     
        while(A[index]<A[index+1]) index++
        return index
    };
```