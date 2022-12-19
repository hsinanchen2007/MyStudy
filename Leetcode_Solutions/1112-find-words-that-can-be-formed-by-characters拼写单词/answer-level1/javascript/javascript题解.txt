全程Map.

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let map = new Map();
    for (let i = 0; i < chars.length; i++) {
        let char = chars[i];
        if (!map.get(char)) {
            map.set(char, 1);
        } else {
            map.set(char, map.get(char) + 1);
        }
    }

    let length = 0;
    for (word of words) {
        let tmpMap = new Map();
        let flag = true;
        for (let j = 0; j < word.length; j++) {
            let char = word[j];
            if (!map.get(char)) {
                flag = false;
                break;
            }
            if (!tmpMap.get(char)) {
                tmpMap.set(char, 1);
            } else {
                tmpMap.set(char, tmpMap.get(char) + 1);
            }
            if (tmpMap.get(char) > map.get(char)) {
                flag = false;
                break;
            }
        }
        if (flag) length = length + word.length;
    }
    return length;
};
```