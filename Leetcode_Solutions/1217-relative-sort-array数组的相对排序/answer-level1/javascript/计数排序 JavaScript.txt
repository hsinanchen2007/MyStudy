```

var relativeSortArray = function(arr1, arr2) {
    let list = new Array(1001);
    let res = [];
    for (let i = 0; i < list.length; i++) list[i] = 0;
    for (let i = 0; i < arr1.length; i++) {
        list[arr1[i]]++;
    }
    for (let i = 0; i < arr2.length; i++) {
        while (list[arr2[i]] > 0) {
            res.push(arr2[i]);
            list[arr2[i]]--;
        }
    }
    for (let i = 0; i < list.length; i++) {
        while (list[i] > 0) {
            res.push(i);
            list[i]--;
        }
    }
    return res;
};
```
