### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
    var len = A.length;
    var sum1 = 0;
    var i, j, k;
    var flag = false;
    for(i = 0; i < len-2; i++){
        sum1 += A[i];
        var sum2 = A[i+1];
        j = i + 1;
        for(j = i + 2; j < len-1 && sum1 != sum2; j++){
            sum2 += A[j];
        }
        var sum3 = A[j];
        for(k = j + 1; k < len; k++){
            sum3 += A[k];
        }
        if(sum1 == sum2 && sum1 == sum3) {
            flag = true;
            break;
        }
    }
    return flag;
};
```