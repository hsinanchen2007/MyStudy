

```javascript
/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
    if(!words.length) return []
    let wordsLen = words[0].length
    let len = wordsLen * words.length
    let needs = {},ans = []
    for(i of words){
        needs[i] ? needs[i] ++ : needs[i] = 1
    }
    for(let i = 0;i < s.length - len + 1; i++){
        let wm = Object.assign({}, needs)
        for(let j = i;j < i + len - wordsLen + 1; j += wordsLen){
            let conpare = s.slice(j, j + wordsLen)
            if(wm[conpare]){
                wm[conpare] --
            }else{
                break
            }
        }
        if(Object.values(wm).every(i => i === 0)) ans.push(i)
    }
    return ans
};
```