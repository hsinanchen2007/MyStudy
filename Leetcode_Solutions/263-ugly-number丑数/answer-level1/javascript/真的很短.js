```js
var isUgly = function(num) {
  if (num <= 0) return false;

  [2, 3, 5].forEach(item => {
    while (num !== 1 && num % item === 0) num /= item;
  });

  return num === 1;
};
```