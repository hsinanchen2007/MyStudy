`/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    
    let newMagazine = magazine;
    for (var i = 0; i < ransomNote.length; i++) {

        if (newMagazine.indexOf(ransomNote[i]) === -1) {
            return false
        }
        newMagazine = newMagazine.replace(ransomNote[i], '');
    }

    return true;
};`