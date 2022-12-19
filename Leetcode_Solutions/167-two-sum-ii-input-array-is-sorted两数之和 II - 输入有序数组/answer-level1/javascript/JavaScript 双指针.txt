```
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 * 双指针法
 */
var twoSum = function(numbers, target) {
    for (let i = 0, j = numbers.length - 1; i < j;) {
        let left = numbers[i],
            right = numbers[j];
        if (left + right === target)
            return [i + 1, j + 1];
        if (left + right > target) {
            j--;
        } else if (left + right < target) {
            i++;
        }
    }
    return [];
};
```