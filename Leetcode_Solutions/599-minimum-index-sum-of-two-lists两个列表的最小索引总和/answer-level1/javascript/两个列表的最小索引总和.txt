```js
var findRestaurant = function(list1, list2) {
    let map = new Map();
    let res = [];
    list1.forEach((item) => {
    	if (list2.indexOf(item) !== -1) {
            map.set(item, list1.indexOf(item) + list2.indexOf(item))
    	}
    });
    let min = Math.min.apply(Math, [...map.values()])
    for (let [key, val] of map) {
        if (val === min) {
        	res.push(key)
        }
    }
    return res
};
```

