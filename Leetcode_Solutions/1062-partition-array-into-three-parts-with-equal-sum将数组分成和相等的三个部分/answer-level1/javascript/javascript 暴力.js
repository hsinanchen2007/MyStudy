```
var canThreePartsEqualSum = function(A) {
	const target = A.reduce((t, i) => t + i, 0) / 3;
	let i = A.length - 1;
	let sum = A[i];
    let part = 0;
	while(i--) {
		if(sum === target) {
            sum = A[i];
            part++;
        }
		else sum += A[i];
	}
	return (sum === target && part === 2) || (sum === 0 && part === 3);
};
```
