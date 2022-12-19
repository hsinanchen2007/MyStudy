### 解题思路
对数组排序，一个while循环逐渐将数组开头K个数填入新数组中
### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    if(arr.length==0) return 0;
    if(k==arr.length) return arr;
    arr.sort((a,b)=>{return a-b});
    let newArr=[];
    while(k>0){
        newArr.push(arr.shift());
        k--;
    }
    return newArr;
};
```