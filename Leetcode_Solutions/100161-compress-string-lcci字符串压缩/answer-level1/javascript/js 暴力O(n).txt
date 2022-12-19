```js
var compressString = function(S) {
	let res = '';
    let j;
	const len = S.length;
	for(let i = 0; i < len; i++) {
		res += S[i];
		j = i;
		while(S[i] === S[j + 1]) j++;
		res += j - i + 1;
		i = j;
	}
	return res.length < len ? res : S;
};
```
