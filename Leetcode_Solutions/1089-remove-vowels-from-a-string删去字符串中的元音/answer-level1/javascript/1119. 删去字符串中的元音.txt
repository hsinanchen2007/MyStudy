### 正则表达式

直接用正则表达式匹配元音字母，匹配到就直接去除

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var removeVowels = function(S) {
    return S.replace(/[aeiou]/g, '')
};
```

### 循环替换

循环匹配，如果碰到元音字母就跳过，否则直接添加到结果中

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var removeVowels = function(S) {
    let res = ''
    let vowels = [ 'a', 'e', 'i', 'o', 'u' ]
    for (let i = 0; i < S.length; i++) {
        let character = S.charAt(i)
        if (vowels.some((vowel) => vowel === character)) {
            continue
        }
        res += character
    }
    return res
};
```