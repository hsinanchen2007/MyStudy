```
var reverseWords = function(s) {
  const SPACE = ' ';
  let ret = [],
    word = [];
  s += SPACE;

  for (let i = 0; i < s.length; i++) {
    const char = s[i];
    if (char === SPACE) {
      if (i !== 0 && s[i - 1] !== SPACE) {
        ret.unshift(word.join(''));
        word = [];
      } else {
        continue;
      }
    } else {
      word.push(char);
    }
  }

  return ret.join(SPACE);
};

```

