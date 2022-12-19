使用二分查找求解，时间复杂度为O(nlogn)

```
var twoSum = function(numbers, target) {
    for(i = 0; i< numbers.length; i++){
        let other = target - numbers[i];
        let searchResult = binarySearch(numbers,other);
        if (searchResult != -1 && i != searchResult){
            return i < searchResult ? [i + 1 , searchResult + 1] : [searchResult + 1,i + 1];
        }
    }
    return [];
};

const binarySearch = function (numbers,target){
    var low = 0;
    var high = numbers.length - 1;
    while(low <= high){
        var middle = parseInt((low + high) / 2);
        if (numbers[middle] == target){
            return middle;
        }else if(numbers[middle] > target){
            high = middle - 1;
        }else{
            low = middle + 1;
        }
    }
    return -1;
}
```