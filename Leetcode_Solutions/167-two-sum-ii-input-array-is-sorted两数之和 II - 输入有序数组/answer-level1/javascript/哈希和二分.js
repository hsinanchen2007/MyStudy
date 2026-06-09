### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (numbers, target) {
    //使用哈希
    let map = new Map()
    for (let i = 0; i < numbers.length; i++) {
        let key = -numbers[i] + target
        if (map.has(key)) {
            return [map.get(key) + 1, i + 1]
        } else {
            map.set(numbers[i], i)
        }
    }
};
```

### 代码
```javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (numbers, target) {
    //有序数组，所以使用双指针
    let i = 0, j = numbers.length - 1
    while (i < j) {
        if (numbers[i] + numbers[j] > target) {
            j--
        } else if (numbers[i] + numbers[j] < target) {
            i++
        } else if (numbers[i] + numbers[j] == target) {
            return [i+1, j+1]
        }
    }
};
```