

先记录查询前原数组偶数和S,
对于每次查询 如果A[index] 是偶数，S -= A[index],
如果A[index] + VAL 是偶数， S += A[index] + VAL。


```js
var sumEvenAfterQueries = function(A, queries) {
    let qLen = queries.length;
    let ALen = A.length;
    let res = [];
    let evenSum = 0;
    A.forEach((item) => {
        if (item % 2 == 0) {
        	evenSum += item
        }
    })
    for (let i = 0; i < qLen; i++) {
    	let index = queries[i][1]
    	let val = queries[i][0]
        if (A[index] % 2 == 0) {
        	evenSum -= A[index]
        } 
        A[index] += val
        if (A[index] % 2 == 0) {
        	evenSum += A[index]
        }
    	res.push(evenSum)
    }
    return res
};
```

