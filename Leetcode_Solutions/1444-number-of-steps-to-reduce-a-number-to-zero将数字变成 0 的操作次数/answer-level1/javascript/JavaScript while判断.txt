### 解题思路
![image.png](https://pic.leetcode-cn.com/5bb51b44aa2e963b6fe02873adf1478f2d86e46e6274233d8435fb8f9a6b7110-image.png)

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps  = function(num) {
    let sum = 0
    debugger;
    while(num != 0){
        sum++
        if(num % 2 == 0){
            num = num /2
        }else{
            num--
        }
    }
    return sum
};
```
