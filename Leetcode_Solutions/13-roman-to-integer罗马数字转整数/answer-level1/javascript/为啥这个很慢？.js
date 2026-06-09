```javascript []
var romanToInt = function(s) {
  const roman = {
    IV: 4,
    IX: 9,
    XL: 40,
    XC: 90,
    CD: 400,
    CM: 900,
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000
  };

  const regExp = RegExp(Object.keys(roman).join("|"), "g");
  const arr = s.match(regExp);

  return arr.reduce((prev, current) => prev + roman[current], 0);
};
```
