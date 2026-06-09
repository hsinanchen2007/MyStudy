### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps = function (num) {
    let count = 0
    while (num !== 0) {

        // 判断奇偶 偶数求余为0
        if (num % 2 === 0) {
            num = num
        } else {
            num = num - 1
            count++
        }
        if(num === 0){
            return count
        }
        num /= 2
        count++
    }

};
```