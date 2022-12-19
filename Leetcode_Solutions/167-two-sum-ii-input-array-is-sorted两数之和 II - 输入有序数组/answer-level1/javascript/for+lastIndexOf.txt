### 解题思路
此处撰写解题思路
for遍历， target减每一个元素的到得值通过lastIndexOf，看numbers中存在吗？同时过滤掉索引相同得值
### 代码

```javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (numbers, target) {
    for (let i = 0; i < numbers.length; i++) {
        if (target - numbers[i] >= 0) {
            let index = numbers.lastIndexOf(target - numbers[i])
            if (index >= i) {
                return [i + 1, index + 1]
            }
        }
    }
};
```