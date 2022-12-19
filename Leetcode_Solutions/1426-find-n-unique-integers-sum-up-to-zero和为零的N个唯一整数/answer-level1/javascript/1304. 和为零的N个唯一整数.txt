### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var sumZero = function(n) {
    let result = []
    if(n%2 === 1){
        result.push(0)
        for(let i = 0; i < (n - 1 )/2; i++){
            result.push(i + 1)
            result.unshift( -i - 1)
        }
    }else{
        for(let i = 0; i < n/2; i++){
            result.push(i + 1)
            result.unshift( -i - 1)
        }
    }
    return result
};
```