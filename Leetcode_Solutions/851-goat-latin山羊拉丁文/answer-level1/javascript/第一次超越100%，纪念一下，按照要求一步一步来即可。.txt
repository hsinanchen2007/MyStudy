```
/**
 * @param {string} S
 * @return {string}
 */
var toGoatLatin = function(S) {
    let sArr = S.split(' ')
    for (let i = 0; i < sArr.length; i++) {
        let start = sArr[i].charAt(0).toLowerCase()
        if (start === 'a' || start === 'e' || start === 'i' || start === 'o' || start === 'u') {
            sArr[i] = sArr[i] + 'ma'
        } else {
            let s1 = sArr[i].charAt(0)
            let s2 = (sArr[i] + s1 + 'ma').substring(1)
            sArr[i] = s2
        }
        for (let j = 0; j < i + 1; j++) {
            sArr[i] = sArr[i] + 'a'
        }
    }
    return sArr.join(' ')
};
```