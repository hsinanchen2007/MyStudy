```javascript
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    let hash = {}
    
    let i = 0
    
    while(i < magazine.length) {
        if (hash[magazine[i]]) {
            hash[magazine[i]]++;
        } else {
            hash[magazine[i]] = 1;
        }
        
        i++
    }
    
    i = 0
    
    while(i < ransomNote.length) {
        if (hash[ransomNote[i]]) {
            hash[ransomNote[i]]--
        } else {
            return false
        }
        i++
    }
    
    return true
};
```