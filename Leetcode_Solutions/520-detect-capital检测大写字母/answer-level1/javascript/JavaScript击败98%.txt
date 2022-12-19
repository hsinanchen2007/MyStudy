```
var detectCapitalUse = function(word) {
  if(word.toUpperCase() == word|| word.toLowerCase() == word) {
      return true;
  }else{
      if(/[A-Z]/.test(word[0])) {
          let boo = 1;
          for(let i = 1; i <= word.length; i++) {
              if(/[A-Z]/.test(word[i])) {
                  ++boo;
              }
          }
          if(boo == 1) {
              return true;
          }
          return false;
      }else{
          return false;
      }
  }
};
```
