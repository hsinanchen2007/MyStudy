
*法一*

```js
var uncommonFromSentences = function(A, B) {
    let aArr = A.split(' ')
    let bArr = B.split(' ')
    let aMap = new Map()
    let bMap = new Map()
    let aOnce = []
    let bOnce = []
    for (let i = 0; i < aArr.length; i++) {
    	if (!aMap.has(aArr[i])) {
            aMap.set(aArr[i], 1)
    	} else {
    		aMap.set(aArr[i], aMap.get(aArr[i]) + 1)
    	}
    }
    for (let i = 0; i < bArr.length; i++) {
    	if (!bMap.has(bArr[i])) {
            bMap.set(bArr[i], 1)
    	} else {
    		bMap.set(bArr[i], bMap.get(bArr[i]) + 1)
    	}
    }
    for (let [key, val] of aMap) {
    	if (val === 1) {
    		aOnce.push(key)
    	}
    }
    for (let [key, val] of bMap) {
    	if (val === 1) {
    		bOnce.push(key)
    	}
    }
    let aa = aOnce.filter((item) => {
    	return  !bArr.includes(item)
    })
    let bb = bOnce.filter((item) => {
    	return  !aArr.includes(item)
    })
    return aa.concat(bb)
};
```

*法二*

拼接字符串A+B，然后返回拼接后的字符串中只出现过一次的单词

```js
var uncommonFromSentences = function(A, B) {
    let arr = (A + ' ' + B).split(' ');   
    return arr.filter(i => arr.indexOf(i) == arr.lastIndexOf(i));
};
```