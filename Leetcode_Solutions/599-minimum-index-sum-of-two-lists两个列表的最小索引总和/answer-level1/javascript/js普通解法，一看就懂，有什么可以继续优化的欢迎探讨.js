```
var findRestaurant = function (list1, list2) {
    let arr = [];
    let index, result = [];
    for (let i = 0, len = list1.length; i < len; i++) {
        arr[list1[i]] = i;
    }
    for (let i = 0, len = list2.length; i < len; i++) {
        if (arr[list2[i]] != undefined) {
            let newIndex = arr[list2[i]] + i;
            if (newIndex < index) {
                result.length = 0;
                result.push(list2[i]);
                index = newIndex;
            } else if (newIndex == index) {
                result.push(list2[i]);
            } else if (index == undefined) {
                result.push(list2[i]);
                index = newIndex;
            }
        }
    }
    return result
};
```
