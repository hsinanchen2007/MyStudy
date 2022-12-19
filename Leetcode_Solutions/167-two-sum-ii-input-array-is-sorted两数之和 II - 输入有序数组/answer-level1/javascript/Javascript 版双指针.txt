相较于 `Two Sum 1`, 我们获取的是排序后的数列，因此较好的方法是用双指针，一个指向首位，一个指向末尾，通过对比两者指向元素之和与目标的大小，来遍历我们的数组:

>执行用时 :80 ms, 在所有 JavaScript 提交中击败了89.08%的用户
```Javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (numbers, target) {
    let left = 0;
    let right = numbers.length - 1;

    if (numbers.length <= 2) {
        return [++left, ++right];
    }
    
    while (left < right) {
        if (numbers[left] + numbers[right] > target) {
            right--;
        } else if (numbers[left] + numbers[right] < target) {
            left++;
        } else {
            return [++left, ++right];
        }
    }
};
```