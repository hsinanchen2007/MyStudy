```js
var buddyStrings = function(A, B) {
    let aLen = A.length;
    let bLen = B.length;
    if (aLen !== bLen) {
    	return false
    }
    if (A === B) {
    	return new Set(A).size !== A.length
    }
    let start;
    let end;
    for (let i = 0; i < aLen; i++) {
    	if (A[i] !== B[i]) {
            start = i;
            break;
    	}
    }
    for (let i = aLen-1; i >= 0; i--) {
    	if (A[i] !== B[i]) {
            end = i;
            break;
    	}
    }
    let arr = A.split('');
    [arr[start],arr[end]] = [arr[end],arr[start]]
    return arr.join('') === B
};
```