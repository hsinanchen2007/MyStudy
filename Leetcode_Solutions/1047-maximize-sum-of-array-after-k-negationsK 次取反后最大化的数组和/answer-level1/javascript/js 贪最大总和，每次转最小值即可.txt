```
// 时间：O(N) 空间 O(1)
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var largestSumAfterKNegations = function(A, K) {
    // 排序
    A.sort((a,b) => {return a-b})
    let i = 0, len = A.length
    // 将所有小于0的转正，如果还需逆转，转之前在0两端两个位置的最小值
    while(i < len && K > 0){
        if(A[i] < 0){
            A[i] = -A[i]
            i++
            K--
        }else{
            let index = A[i] >= A[i-1] ? i-1 : i
            A[index] = K % 2 === 0 ? A[index] : -A[index]
            K = 0
        }
    }
    // 如果A均为负，转完之后，K还有值，则转当前最小的数
    if(K !== 0){
        A[len-1] = K % 2 === 0 ? A[len-1] : -A[len-1]
    }
    // 求和
    let sum = 0
    for(let j = 0; j < len; j++){
        sum += A[j]
    }
    return sum
};
```
