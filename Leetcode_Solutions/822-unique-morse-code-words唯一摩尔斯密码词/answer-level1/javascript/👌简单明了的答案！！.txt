```
/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function (words) {
    let arr = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."],
        ans = []
    words.forEach(word => {
        let len = word.length, str = '';
        for (let c of word) {
            let i = c.charCodeAt() - 97
            str += arr[i]
            len--
        }
        ans.push(str)
    })
    return new Set(ans).size
};
```
