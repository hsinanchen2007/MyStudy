```js
var decodeString = function (s) {
  const reg = /(\d+)\[(\w+)\]/g;
  let matches = s.match(reg);
  while (matches) {
    s = s.replace(reg, (_, times, str) => str.repeat(times));
    matches = s.match(reg);
  }
  return s;
};
```