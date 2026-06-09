
```
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    let len = numbers.length
    for(let i = 0; i < len; i++){
        let l = i + 1
        let r = len - 1
        while(l <= r) {
            let mid = Math.floor((l + r) / 2)
            if(numbers[i] + numbers[mid] == target) {
                return [i+1,mid+1]
            } else if(numbers[i] + numbers[mid] > target){
                r = mid - 1
            } else if(numbers[i] + numbers[mid] < target){
                l = mid + 1
            }
        }
    }    
};
```
