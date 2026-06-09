### 解题思路
![image.png](https://pic.leetcode-cn.com/1f5a2f74910a22b20ff5b4e0614218e653b2e403efc5d074bdc08e319fd855eb-image.png)

- 两次循环遍历，根据题目条件进行判断
- 如果满足条件 则num++

### 代码

```javascript
/**
 * @param {number[][]} dominoes
 * @return {number}
 */
var numEquivDominoPairs = function(dominoes) {
    let row = dominoes.length
    let num = 0
    for(let i = 0; i < row; i++){
        for(let j = i+1 ; j < row; j++){
            if((dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]) || (dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0])){
                num++
            }
        }
    }
    return num
};
```