优点：思路简便，方便快速
缺点： 无法体现详细的思路
```
var addBinary = function(a, b) {
    return (BigInt(`0b${a}`)+BigInt(`0b${b}`)).toString(2)
};
```
