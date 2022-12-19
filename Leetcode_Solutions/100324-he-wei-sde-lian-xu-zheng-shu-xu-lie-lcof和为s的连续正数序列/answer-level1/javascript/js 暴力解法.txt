### 解题思路
 暴力的方法，1 ~ target / 2，每个数开始，加起来看看是否相等于target
 小于则继续加，大于则不成立，等于则数组有效
### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let result = [];
    //1
    if(target === 1) {
        return result;
    }

    //从1 开始 到 Math.ceil(target / 2)
    for(let i = 1; i < Math.ceil(target / 2); i++) {
        let sum = 0;
        let acc = i;
        while(sum <= target) {
            if(sum < target) {
                sum += acc++;
            } else if(sum === target){
                //equal array from i ~ acc
                let array = [];
                for(let index = i; index < acc; index++) {
                    array.push(index);
                }

                result.push(array);

                break;
            }
        }
    }

    return result;
};
```