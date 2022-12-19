```
var countCharacters = function(words, chars) {
    let res = 0;
    let len = words.length;
    while(len--) {
        let i = words[len].length;
        let copy = chars;
        while(i--) {
            let index = copy.indexOf(words[len][i]);
            if(index < 0) break;
            copy = copy.slice(0, index) + copy.slice(index+1);
        }
        if(i < 0) res += words[len].length;
    }
    return res;
};
```
