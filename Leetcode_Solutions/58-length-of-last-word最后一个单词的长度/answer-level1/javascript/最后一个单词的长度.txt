```js
var lengthOfLastWord = function(s) {
    let trimS = s.trim();
    let sToArr = trimS.split(/\s+/);
    let len = sToArr.length;
    return sToArr[len - 1].length;
};

var s = "Hello  World ";
console.log(lengthOfLastWord(s))
```