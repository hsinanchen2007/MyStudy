### 解题思路
![image.png](https://pic.leetcode-cn.com/95446908d15f05d971f9b8fc7d3e4f278cff3c74391e2f47eb61dcb3cbac87fe-image.png)

- 主要去阅读题目意思，统计题目中的奇数和偶数的数量
- 返回数量少的那个

### 代码

```javascript
/**
 * @param {number[]} chips
 * @return {number}
 */
var minCostToMoveChips = function(chips) {
    let sum = 0
    let numA = 0
    let numB = 0
    for(let i = 0; i < chips.length; i++){
        if(chips[i] % 2 == 1){
            numA++
        } else{
            numB++
        }
    }
    return numA > numB ? numB : numA
};
```