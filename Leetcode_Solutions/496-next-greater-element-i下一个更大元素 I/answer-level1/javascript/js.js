![image.png](https://pic.leetcode-cn.com/2fe545605b4b148a1cbc6c0da79deb20781fede94b9b7d8475bef475b7bd788b-image.png)
```
// 基于基数排序
var nextGreaterElement = function(arr1, arr2) {
    if (!arr1.length)
        return arr1;
    let list = new Array(1001);
    for (let i = 0; i < arr2.length; i++) {
        let next = -1;
        for (let j = i + 1; j < arr2.length; j++) {
            if (arr2[j] > arr2[i]) {
                next = arr2[j];
                break;
            }
        }
        list[arr2[i]] = next;
    }
    for (let i = 0; i < arr1.length; i++)
        arr1[i] = list[arr1[i]];
    return arr1;
};
 

// Map
let nextGreaterElement1 = function(arr1, arr2) {
    let map = new Map();
    for (let i = 0; i < arr2.length; i++) {
        let k = i;
        let next = -1;
        while (k++ < arr2.length) {
            if (arr2[k] > arr2[i]) {
                next = arr2[k];
                break;
            }
        }
        map.set(arr2[i], next);
    }
    for (let i = 0; i < arr1.length; i++)
        arr1[i] = map.get(arr1[i]);
    return arr1;
}


let nextGreaterElement2  = function(arr1, arr2) {
    return arr1.map(item => {
        for (let i = arr2.indexOf(item); i < arr2.length; i++) {
            if (arr2[i] > item)
                return arr2[i]
        }
        return -1;
    })
}

```
