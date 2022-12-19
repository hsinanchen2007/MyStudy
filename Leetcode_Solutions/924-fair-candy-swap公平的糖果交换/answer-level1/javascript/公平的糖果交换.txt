```js
var fairCandySwap = function(A, B) {
	let sumA = 0;
	let sumB = 0;
    for (let item of A) {
        sumA += item
    }
    for (let item of B) {
        sumB += item
    }
    let diff = (sumA - sumB) / 2;
    for (let i = 0; i < A.length; i++) {
    	for (let j = 0; j < B.length; j++) {
    		if (A[i]-B[j] === diff) {
    			return [A[i], B[j]]
    		}
    	}
    }
};
```