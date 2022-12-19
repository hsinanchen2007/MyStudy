```
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    let len1 = ransomNote.length;
    magazine = magazine.split("");
    for (let i = 0; i < len1; i++) {
        let curr = ransomNote.charAt(i);
        let target = magazine.indexOf(curr);
        if (target >= 0) {
            magazine.splice(target, 1);
        } else {
            return false;
        }
    }
    return true;
};
```
