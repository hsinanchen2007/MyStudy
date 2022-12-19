```javascript []
var uniqueMorseRepresentations = function(words) {
    let morseMap = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
    return new Set(words.map(word=>{
        return Array.from(word).reduce((total,w)=>{
           return total += morseMap[w.charCodeAt()-97]
        },"")
    })).size
};
```