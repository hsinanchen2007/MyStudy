```js
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    var current_magazine
    for (var i = 0; i < ransomNote.length; i++) {
        current_magazine = magazine.replace(ransomNote[i], '')
        if (current_magazine.length === magazine.length) {
            return false
        }
        magazine = current_magazine
    }
    return true
};
```
