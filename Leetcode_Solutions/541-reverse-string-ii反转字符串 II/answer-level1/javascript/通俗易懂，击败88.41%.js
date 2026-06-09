```
var reverseStr = function(s, k) {
    if (!s) return "";
    let arr = s.split("");
    let tempArr = [];
    while (arr.length > 0) {
        let len = arr.length;
        if (len < k) {
            return tempArr.concat(arr.reverse()).join("");
        } else if (len <= 2 * k) {
            let temp = arr.splice(0, k).reverse();
            tempArr = tempArr.concat(temp, arr);
            return tempArr.join("");
        } else {
            let temp = arr.splice(0, k).reverse();
            tempArr = tempArr.concat(temp, arr.splice(0, k));
        }
    }
};
```
