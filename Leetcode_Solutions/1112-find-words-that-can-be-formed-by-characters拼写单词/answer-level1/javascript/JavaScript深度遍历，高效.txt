### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    var checked = new Array().fill(false);
    this.len = 0;
    for(var i = 0; i < words.length; i++){
        dfs(checked, chars, words[i], words[i].length);
    }
    return len;
};

var dfs = function(checked, chars, word, n){
    if(n == 0) {
        this.len += word.length;
        return;
    }else{
        for(var j = 0; j < chars.length; j++){
            if(checked[j]) continue;
            if(word[n-1] == chars[j]){
                checked[j] = true;
                dfs(checked, chars, word, n-1);
                checked[j] = false;
                break;
            }
        }
    }
}
```