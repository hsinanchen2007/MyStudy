### 解题思路
此处撰写解题思路
先根据n放入n/2对数据进入res，最后判断n是否是奇数，是的话添一个0后返回res，n是偶数直接返回res
### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var sumZero = function(n) {
    let res = []
    let index = 0
    for(let i=1; i<=n/2; i++){
        res[index++] = -i
        res[index++] = i
    }
    if(n%2 == 0){
        return res
    }else{
        res.push(0)
        return res
    }
    return 0
};
```