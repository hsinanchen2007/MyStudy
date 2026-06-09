思路:全大写或者全小写->true，除首位出现大写->false
```
var detectCapitalUse = function(word) {
  let flag = true;
  if (word === word.toLowerCase() || word === word.toUpperCase()) return true;
  for (let i = 1; i < word.length; i++) {
    if (word.charAt(i) !== word.charAt(i).toLowerCase()) {
      return false;
    }
  }
  return true;
};
```
