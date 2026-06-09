```
var searchMatrix = function(matrix, target) {
    for(let i = 0; i < matrix.length; i++) {
        if(binarySearch(matrix[i], target)) {
            return true;
        }
    }
    return false
};

var binarySearch = function (arr, target) {
    let l = 0;
    let r = arr.length - 1;
    
    while(l <= r) {
        var mid = Math.floor((l + r) / 2);
        if(arr[mid] == target) {
            return true;
        } else if(arr[mid] > target) {
             
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return false;
}
```