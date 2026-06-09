```
var lengthOfLastWord = function(s) {
    var a = s.split(" ").filter(item=>item);
    return a.length
    ?
    a.pop().length
    :
    0
};

```
