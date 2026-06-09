```js
var reverseStr = function(s, k) {
  let res = "";

  while (s) {
    res += s
      .slice(0, k)
      .split("")
      .reverse()
      .join("");

    res += s.slice(k, k * 2);

    s = s.slice(k * 2);
  }

  return res;
};


// 效率较低
var reverseStr = function(s, k) {
  let n = 0;

  s = s.split("");

  while (s.length > n * 2 * k) {
    const offset = n * k * 2;

    const part = s.slice(offset, offset + k * 2);

    let max = Math.min(part.length, k);
    let mid = ~~(max / 2);

    max += offset;
    mid += offset;

    for (let i = offset; i < mid; i++) {
      const tmp = s[i];
      s[i] = s[max - i - 1 + offset];
      s[max - i - 1 + offset] = tmp;
    }

    n++;
  }

  return s.join("");
};

```



