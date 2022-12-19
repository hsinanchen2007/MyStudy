
解题思路：

1. 将pattern和str存储为key【单词】，value【索引数组】

2. 对比objPat和objStr中单词出现的索引是否一样

```js
var pattern = "abba";
var str = "dog cat dog cat";

var objPat = {
'a': [0, 3],
'b': [1, 2]
};
var objStr = {
'dog': [1, 3],
'cat': [0, 2]
};
```

```js
var wordPattern = function(pattern, str) {
    var arr = str.split(' ');
    if (pattern.length !== arr.length) {
    	return false;
    }
    var objPat = {};
    var objStr = {};
    for (let j = 0; j < pattern.length; j++) {
        if (!objPat[pattern[j]]) {
        	objPat[pattern[j]] = [j]
        } else {
        	objPat[pattern[j]].push(j)
        }
    }
    for (let j = 0; j < arr.length; j++) {
        if (!objStr[arr[j]]) {
        	objStr[arr[j]] = [j]
        } else {
        	objStr[arr[j]].push(j)
        }
    }
    if (Object.keys(objPat).length !== Object.keys(objStr).length) {
    	return false;
    }
    for (let k = 0; k < Object.keys(objPat).length; k++) {
        for (let m = 0; m < objPat[Object.keys(objPat)[k]].length; m++) {
        	if (objPat[Object.keys(objPat)[k]][m] !== objStr[Object.keys(objStr)[k]][m]) {
        		return false
        	}
        }
        return true
    }
    return true;
};
```

