```
/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
// 时间 O(N*N) 空间 O(N)
var advantageCount = function(A, B) {
    A.sort((a,b) => {return a-b})
    let res = []
    for(let i = 0; i < B.length; i++){
        let isOk = false
        for(let j = 0; j < A.length; j++){
            if(A[j] > B[i]) {
                isOk = true
                res.push(A.splice(j,1)[0])
                break
            }
        }
        if(!isOk) {
            res.push(A.splice(0,1)[0])
        }
    }
    return res
};
```