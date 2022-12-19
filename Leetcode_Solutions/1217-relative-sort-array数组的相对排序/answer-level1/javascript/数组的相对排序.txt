```js
var relativeSortArray = function(arr1, arr2) {
    // arr1 中没有出现在 arr2 中的元素
    let arr3 = []
    let map = new Map()
    for(let i = 0; i < arr1.length; i++) {
    	let index = arr2.indexOf(arr1[i])
    	if (index != -1) {
    		if (!map.has(arr1[i])) {
    			map.set(arr1[i], true)
    			arr2.splice(index,1, arr1[i])
    		} else {
    			arr2.splice(index,0, arr1[i])
    		}
    	} else {
    		arr3.push(arr1[i])
    	}
    }
    arr3.sort((a, b) => a - b)
    return arr2.concat(arr3)
};
```
