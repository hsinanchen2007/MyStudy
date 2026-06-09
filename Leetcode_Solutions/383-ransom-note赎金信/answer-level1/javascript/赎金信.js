```js
var canConstruct = function(ransomNote, magazine) {
    for (let i = 0; i < ransomNote.length; i++) {
        let index = magazine.indexOf(ransomNote[i])
        if (index === -1) {
            return false
        } else {
            magazine = magazine.substring(0, index) + magazine.substring(index + 1, magazine.length)

        }
    }
    return true
};
```
