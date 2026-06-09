### 解题思路
可以想成当前值和当前最大值的+1的差的和

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    A = A.sort((x,y)=>x-y);
    let max = A[0];
    let result = 0;
    for(let i = 1;i<A.length;i++){
        if(max < A[i]){
            max = A[i]
        }else{
            max = max +1
            result +=  max - A[i]
        }
    }
    return result;
};
```