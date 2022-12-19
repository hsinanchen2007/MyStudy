```javascript
var uniqueMorseRepresentations = function (words) {
    let result = [];
    let morse = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."];
    let az = "abcdefghijklmnopqrstuvwxyz";
    words.forEach(element => {
        let arr = element.split('');
        let trans = '';
        arr.forEach(char => {
            trans += morse[az.indexOf(char)];
        });
        if (result.indexOf(trans) < 0) {
            result.push(trans);
        }
    });
    return result.length;
};
```