### 解题思路
此处撰写解题思路
使用对象属性解题
### 代码

```javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
 const map = {};
  for (let i = 0; i < numbers.length; i++) {
    const current = target - numbers[i];

    if (numbers[i] in map) {
      return [map[numbers[i]]+1, i+1];
    }
    map[current] = i;
  }
};
```