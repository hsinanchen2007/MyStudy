### 解题思路
![image.png](https://pic.leetcode-cn.com/cd4d339f710fa7da941ae325958afa6bd379ca46de8a07423869d05d58958f58-image.png)

- 环形求和，起始点和终点不一，通过判断起始点和终点的 Index 大小 进行对比



### 代码

```javascript
/**
 * @param {number[]} distance
 * @param {number} start
 * @param {number} destination
 * @return {number}
 */
var distanceBetweenBusStops = function(distance, start, destination) {
    let numA = 0
    let numB = 0
    let sum = distance.reduce((pre, next) => {
        return pre + next
    })
    if(destination > start){
    for(let i = start; i < destination; i++){
        numA += distance[i]
    }
    numB = sum - numA
    return Math.min(numA,numB)        
    } else{
        for(let j = destination; j < start; j++){
            numA += distance[j]
        }
    numB = sum - numA
    return Math.min(numA,numB) 
    }

};
```