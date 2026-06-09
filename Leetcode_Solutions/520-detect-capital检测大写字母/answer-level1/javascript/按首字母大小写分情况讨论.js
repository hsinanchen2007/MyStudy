### 解题思路

按首字母大小写分情况讨论

只有下面两种情况，合法

1. 首字母大写
    剩下的都是大写 || 剩下的 都是小写
2. 首字母小写
    剩下的都是小写

### 代码

```javascript
/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    if (word[0] >= 'A' && word[0] <='Z'){ // 首字母大写
        return allLower(word.substr(1)) || allUper(word.substr(1))
    }else { // 首字母小写
        return allLower(word)
    }
};

var allLower = function(word){
    for (let i = 0; i < word.length; i++){
        if (word[i] >= 'A' && word[i]<='Z') return false
    }
    return true
}

var allUper = function(word){
    for (let i = 0; i < word.length; i++){
        if ( word[i] < 'A' || word[i]>'Z') return false
    }
    return true
}
```