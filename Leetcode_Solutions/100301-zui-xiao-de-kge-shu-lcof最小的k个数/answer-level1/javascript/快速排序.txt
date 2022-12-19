**方法一、内置排序函数**
```
var getLeastNumbers = function(arr, k) {
    arr.sort((a,b)=>a-b);
    return arr.slice(0,k);
};
```
**方法二、快速排序**
```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    var len=arr.length;
    var start=0;
    var end=len-1;
    if(!len || !k) return [];
//先以数组的第一个元素为标杆，进行快速排序，小于该值放到数组左边，大于该值放到数组右边，
//返回该值在整个数组排序之后的正确的索引
    var index = quickSort(arr,start,end);
    while(index !== k-1){
        if(index > k-1){
            end = index-1;
            index = quickSort(arr,start,end);
        }else{
            start = index+1;
            index = quickSort(arr,start,end);
        }
    }
    return arr.slice(0,k);
};
//该函数返回标杆值在数组中的正确的索引位置，每一次都是将大于该值的数放到该值右侧，小于该值的放到该值左侧
function quickSort(arr,left,right){
    var pivot = arr[left];
    while(left<right){
        while(left<right && arr[right]>=pivot){
            right--;
        }
        arr[left]=arr[right];
        while(left<right && arr[left]<pivot){
            left++;
        }
        arr[right]=arr[left];
    }
    arr[left]=pivot;
    return left;
}
```
**方法三、堆排序**
```
代码块
```
