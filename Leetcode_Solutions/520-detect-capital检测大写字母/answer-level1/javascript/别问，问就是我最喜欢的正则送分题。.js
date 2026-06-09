```
var detectCapitalUse = function(word) {
    let reg1 = /^[A-Z]*$/;
    let reg2 = /^[A-Z][a-z]*$/;
    let reg3 = /^[a-z]*$/;
    return reg1.test(word) || reg2.test(word) || reg3.test(word);
};
```
