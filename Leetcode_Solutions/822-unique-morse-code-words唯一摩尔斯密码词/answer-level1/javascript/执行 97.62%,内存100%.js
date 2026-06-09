先把大的用reduce切分到小的，然后把每个小的转义成相应的字符，Set去重。
```
function trans(wordArr) {
    const mosArr = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
    const passWordArr = transformToPassWord(wordArr);
    function transformToPassWord(wordArr){
        return wordArr.reduce(((acc, cur) => {
            const concatWord = transSingleWord(cur)
            acc.push(concatWord);
            return acc;
        }), []);
    }
    function transSingleWord(word) {
        return word.split("").reduce(((acc, cur) => {
            return acc + mosArr[cur.charCodeAt() - 97];
        }), "")
    }
    return [...new Set(passWordArr)].length;
}
```


