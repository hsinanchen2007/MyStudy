# 解法一： 用时180ms，空间38M
```
const lengthOfLongestSubstring = (str) => {
  let result = 0;
  let map = {};
  let slideWindow = [];

  for(let c of str) {
    if(map[c]) {
      const delIndex = slideWindow.findIndex(ietm => ietm === c);
      for(let i = 0; i < delIndex; i++) {
        map[slideWindow[i]] = false;
      }
      slideWindow = slideWindow.slice(delIndex + 1).concat(c);
    } else {
      if(slideWindow.push(c) > result) {
        result = slideWindow.length;
      }
    }
    map[c] = true;
  }
  return result;
```

# 解法二 用时100ms,空间38M
```
const lengthOfLongestSubstring = (str) => {
  let result = 0;
  let currentStr = '';
  let windowLen = 0;

  for(let c of str) {
    if(currentStr.indexOf(c) === -1) {
      currentStr += c;
      windowLen++;
      result = result > windowLen ? result : windowLen;
    } else {
      currentStr += c;
      currentStr = currentStr.slice(currentStr.indexOf(c) + 1);
      windowLen = currentStr.length;
    }
  }
  return result;
}
```

