### 解题思路
![image.png](https://pic.leetcode-cn.com/3eec9d52cd83e5763de95f760ad24b6f18fbf16f429c3e52a70b25c4a73e7b05-image.png)

- 如图

### 代码

```javascript
/**
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
var countPrimeSetBits = function(L, R) {
    var isPrimeNum = function(num){
    if(num===1) return false
    for(let i = 2 ; i < num; i++){
            if(num % i == 0){
                return false
            }
    }
        return true
    }
    debugger;
    let sum = 0
    for(let i = L; i <= R; i++){
        let tmp = i.toString(2).split('').reduce((pre,next)=>{return parseInt(pre)+parseInt(next)})
        if(isPrimeNum(tmp)){
            sum++
        }
    }
    return sum
};
```