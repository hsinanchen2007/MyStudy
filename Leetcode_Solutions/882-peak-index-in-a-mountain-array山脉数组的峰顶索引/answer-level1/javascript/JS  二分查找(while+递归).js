### while
```js
/**
 * @param {number[]} A
 * @return {number}
 */
var peakIndexInMountainArray = function(A) {
    let low = 0;
    let high = A.length-1
    while(low<=high){
        var mid = parseInt( (low + high) / 2 );
        if(A[mid]>A[mid-1] && A[mid]>A[mid+1]){
            return mid
        }else if(A[mid]>A[mid-1] && A[mid]<A[mid+1]){//最大值在mid右侧
            low = mid+1
        }else if(A[mid]>A[mid+1] && A[mid]<A[mid-1]){
            high = mid-1
        }
    }
};
```

### 递归
```js
/**
 * @param {number[]} A
 * @return {number}
 */
var peakIndexInMountainArray = function(A,low,high) {
     low = low||0;
     high = high||A.length-1
    let mid = parseInt( (low + high) / 2 );
    
    if(A[mid]>A[mid-1] && A[mid]>A[mid+1]){
        return mid
    }else if(A[mid]>A[mid-1] && A[mid]<A[mid+1]){//最大值在mid右侧
        return peakIndexInMountainArray(A,mid+1,high)
    }else if(A[mid]>A[mid+1] && A[mid]<A[mid-1]){
        return peakIndexInMountainArray(A,low,mid-1)
    }
};
```