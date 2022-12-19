```
var defangIPaddr = function(address) {
    if (String.prototype.replace) {
        return address.replace(/\./g, '[.]');
    }
    var arr = address.split("");
    arr.forEach((item, index) => {
        if (item == '.') {
            arr[index] = '[.]'
        }
    })
    return arr.join("")
};
```
