### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
let arr =[4,5,1,6,2,7,3,8]
let k =4;
var getLeastNumbers = function(arr, k) {
    arr = arr.sort((a,b)=>a-b);
    
    let small = arr[0]
   
    arr = arr.splice(0,k)
    
    return arr
};
getLeastNumbers(arr,k)
```