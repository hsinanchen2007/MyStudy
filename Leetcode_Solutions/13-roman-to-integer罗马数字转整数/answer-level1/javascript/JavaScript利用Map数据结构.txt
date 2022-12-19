```js
var romanToInt = function(s) {
  const specialMap = new Map([
    ["IV", 4],
    ["IX", 9],
    ["XC", 90],
    ["XL", 40],
    ["CD", 400],
    ["CM", 900]
  ]);
  const individualMap = new Map([
    ["I", 1],
    ["V", 5],
    ["X", 10],
    ["L", 50],
    ["C", 100],
    ["D", 500],
    ["M", 1000]
  ]);
  const split_s = s.split("");
  const result_arr = [];
  let flat;
  for (let i = 0; i < split_s.length; i++) {
    if (i === flat) {
      continue;
    }
    if (specialMap.has(split_s[i] + split_s[i + 1])) {
      result_arr.push(split_s[i] + split_s[i + 1]);
      flat = i + 1;
    } else {
      result_arr.push(split_s[i]);
    }
  }

  return result_arr.reduce(
    (acc, cur) =>
      acc + (cur.length === 1 ? individualMap.get(cur) : specialMap.get(cur)),
    0
  );
};
```
