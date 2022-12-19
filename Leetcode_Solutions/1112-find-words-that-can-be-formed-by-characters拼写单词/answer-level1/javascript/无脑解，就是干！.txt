```javascript
var countCharacters = function(words, chars) {
    let n = 0;
    for(let word of words) {
        let arr = chars.split('');
        let result = true;
        for(let w of word.split('')){
           const i = arr.findIndex((item, index) => item === w);
           if (i === -1){
               result = false;
               break;
           }
            arr = arr.filter((item, index) => index !== i);
        }
        if(!result){
            continue;
        }
        n += word.split('').length
    }
    return n;
};
```