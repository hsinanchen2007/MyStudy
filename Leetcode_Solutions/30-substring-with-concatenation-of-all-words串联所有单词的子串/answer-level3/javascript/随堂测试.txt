```
var findSubstring = function(s, words) {
  if(s==='' || words.length == 0) return []
  let i = 0;
  const strLen = s.length;
  const wordLen = words[0].length;
  const subLen = wordLen * words.length;
  const ret = [];

  while (i < strLen) {
    if (strLen - i < subLen) {
      return ret;
    }
    const temp = words.slice();
    let j = 0;

    while (true) {
      const index = temp.indexOf(s.substr(i + j * wordLen, wordLen));
      if (index === -1) {
        break;
      } else {
        temp[index] = undefined;
        if ((j + 1) * wordLen === subLen) {
          ret.push(i);
          break;
        }
      }
      j++;
    }
    i++;
  }
  return ret;
};
```
