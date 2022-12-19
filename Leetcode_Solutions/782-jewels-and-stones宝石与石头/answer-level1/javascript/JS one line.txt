```javascript
var numJewelsInStones = function(J, S) {
    return [...S].filter(item => J.indexOf(item)).length;
};
```