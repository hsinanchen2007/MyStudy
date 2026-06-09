```
// 双指针， 时间复杂度O(n) 空间复杂度O(1)
var twoSum = function(numbers, target) {
    var left = 0;
    var right = numbers.length - 1;
    while(left < right) {
        if(numbers[left] + numbers[right] === target) {
            return [left+1, right+1];
        }
        if(numbers[left] + numbers[right] > target) {
            right--;
        }
        if(numbers[left] + numbers[right] < target) {
            left++;
        }
    }
};

// 暴力双循环 时间复杂度O(n*n)， 空间复杂度O(1)
var twoSum = function(numbers, target) {
    for(var i=0; i<numbers.length; i++) {
        for(var j=i+1; j<numbers.length; j++) {
            if(numbers[i] + numbers[j] === target) {
                return [i+1, j+1];
            }
        }
    }
}
```
