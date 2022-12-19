1、暴力法
```javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    if(!numbers) return null;
    for(let i = 0; i < numbers.length; i++) {
        for(let j = i+1; j < numbers.length; j++) {
            if(target - numbers[j] === numbers[i]) {
                return [i+1,j+1]
            }
        }
    }
    return null;
};
```
时间复杂度：O(n^2)
空间复杂度：O(1)


2、双指针
这里也可以理解为二分法
```javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    if(!numbers) return null;
    let l = 0;
    let r = numbers.length - 1;
    while(l < r) {
        let sum = numbers[l] + numbers[r]
        if(sum === target) return [l + 1, r + 1];
        if(sum < target) l ++;
        if(sum > target) r--;

    }
    return null;
};
```
时间复杂度：O(n),每个元素最多被访问一次，共有 n 个元素。
空间复杂度：O(1),只是用了两个指针