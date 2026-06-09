典型的双指针应用

```js
var reverseVowels = function(s) {
    var vowels = "aeiouAEIOU";
    var sArr = s.split('');
    var i = 0;
    var j = s.length - 1;
    while(i < j) {
        if (vowels.indexOf(sArr[i]) === -1 && vowels.indexOf(sArr[j]) !== -1) {
            i++;
        } else if (vowels.indexOf(sArr[i]) !== -1 && vowels.indexOf(sArr[j]) === -1) {
            j--;
        } else if (vowels.indexOf(sArr[i]) === -1 && vowels.indexOf(sArr[j]) === -1) {
            i++;
            j--;
        } else {
            [sArr[i],sArr[j]] = [sArr[j],sArr[i]];
            i++;
            j--;
        }
    }
    return sArr.join('');
};
```