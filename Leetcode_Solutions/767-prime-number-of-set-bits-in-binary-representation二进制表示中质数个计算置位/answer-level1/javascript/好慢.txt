### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
var countPrimeSetBits = function(L, R) {
  let num = 0
  for(let i = L; i <= R; i++){
    let str = i.toString(2)    
    let wei = str.split('').filter(item=>item == 1).length
    if(isZhi(wei)){
      ++num
    } 
  }

  function isZhi(n){
    let flag = true
    if(n===1) return false
    for(let j = 2; j < n;j++){
      if(n % j === 0){
        flag = false
      }
    }
    return flag
  }

  return num
};
```