### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
   
    return quicksort(arr).splice(0,k)
   
};
//快排
var quicksort=function(arr){

    if(arr.length<=1){
        return arr;
    }
    var pivotIndex=Math.floor(arr.length/2);
    var pivot=arr.splice(pivotIndex,1)[0];
    var left=[],right=[];
    arr.forEach(item => {
        if(item<pivot){
            left.push(item)
        }else{
            right.push(item)
        }
    });
    return quicksort(left).concat(pivot,quicksort(right))

}
```