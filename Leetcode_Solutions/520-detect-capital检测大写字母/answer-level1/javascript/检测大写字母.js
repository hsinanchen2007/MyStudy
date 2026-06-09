*法一*

```js
var detectCapitalUse = function(word) {
    if (word.toUpperCase() == word || word.toLowerCase() == word) {
    	return true;
    }
    if (/[A-Z]/.test(word[0])) {
        if (word.substr(1).toLowerCase() == word.substr(1)) {
        	return true
        } else {
        	return false
        }
    }
    return false
};
```

*法二：正则匹配*

```js
var detectCapitalUse = function(word) {
    let patterns = [/^[A-Z]+$/, /^[a-z]+$/, /^[A-Z][a-z]+$/];
    let flag = false
    patterns.forEach((item) => {
        if (item.test(word)) {
        	flag = true
        }
    })
    return flag
};
```

