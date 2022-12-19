```js
var countCharacters = function(words, chars) {
    let res = 0
    for (let i = 0; i < words.length; i++) {
        let chars2 = chars;
        let flag = true;
        for (let j = 0; j < words[i].length; j++) {
            let index = chars2.indexOf(words[i][j])
            if (index !== -1) {
                chars2 = chars2.substr(0, index) + chars2.substr(index+1)
            } else {
                flag = false
            }
        }
        if (flag) {
            res += words[i].length
        }
    }
    return res
};
```
