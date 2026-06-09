```js
  let res = new Map();
  mat.forEach((item, index) => {
    let j = 0;
    item.forEach(i => {
      if (i == 1) {
        j++;
      }
    });
    res.set(index, j);
  });

  let arr = Array.from(res).sort((a, b) => {
    if (a[1] - b[1] == 0) {
      return a[0] - b[0];
//保证索引小的在前面
    }
    return a[1] - b[1];
  });

  let resa = arr.slice(0, k).map(item => item[0]);
  return resa;
```
