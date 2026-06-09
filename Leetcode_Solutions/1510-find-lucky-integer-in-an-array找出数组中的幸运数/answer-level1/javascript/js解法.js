### 解题思路
将数组从小到大排序之后一次遍历获取当前的值，二次遍历计算与当前值相等的数量，如果相等推入数组中，返回数组最后一个值即可。
![image.png](https://pic.leetcode-cn.com/8d037a69ed4d1bb53422b1b670dddc0f665f086a9dbfb9b9b0b05ac1ea8bf792-image.png)

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number}
 */
var findLucky = function(arr) {
    let lucky = [], currentValue
    arr = arr.sort((a, b) => a - b)
    for (let i = 0; i < arr.length; i++) {
        currentValue = arr[i]
        let index = 0
        for (let j = 0; j < arr.length; j++) {
            if (arr[j] === currentValue) {
                index++
            }
        }
        if (currentValue === index) {
            lucky.push(currentValue)
            index = 0
        }
    }
    return lucky.length ? lucky[lucky.length - 1] : -1
};
```