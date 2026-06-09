### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var toGoatLatin = function(S) {
    if(!S.length)return '';
    const words = S.split(' ');
    const vowels = 'aeiouAEIOU';
    const MA = 'ma';
    let A = '';
    for(let i=0; i<words.length; i++){
        A +='a';
        const word = words[i];
        const firstLetter = word[0];
        let replacement;
        if(vowels.includes(firstLetter)){
            replacement = word + MA;
        }else{
            replacement = word.slice(1)+word.slice(0,1)+MA;
        }
        words[i]=replacement+A;
    }
    return words.join(' ');
};
```