```
var addBinary = function (a, b) {
    a = a.split(""), b = b.split("");
    const res = [];
    // 是否需要进位
    let big = false;

    while (a.length || b.length) {
      let c = a.pop(), d = b.pop();
      // 如果数组空了，和运算+0是一样的 
      c = c === undefined ? 0 : +c;
      d = d === undefined ? 0 : +d;

      let sum = c + d;

      if (big) {
        sum += 1;
        big = false;
      }

      if (sum > 1) {
        res.unshift(sum - 2)
        big = true;
      } else {
        res.unshift(sum)
      }

    }
    // 算到最后，还需要进位的话
    if (big) {
      res.unshift(1)
    }

    return res.join("");

  };
```
