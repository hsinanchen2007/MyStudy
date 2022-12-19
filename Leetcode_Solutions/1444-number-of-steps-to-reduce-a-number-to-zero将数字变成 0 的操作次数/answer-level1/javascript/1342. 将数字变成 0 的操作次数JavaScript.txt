### 解题思路
递归

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps  = function(num) {
    let count = 0
    const oneStep = function(num){
        if(num%2){
            count++
            return num - 1
        }else{
            count++
            return num / 2
        }
    }
    while(num){
        num = oneStep(num)
    }
    return count
};
```