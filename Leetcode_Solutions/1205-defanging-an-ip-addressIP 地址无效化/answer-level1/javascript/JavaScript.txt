```
var defangIPaddr = function(address) {
    let reg = /[.]/g
    return address.replace(reg, '[.]')
};
```
