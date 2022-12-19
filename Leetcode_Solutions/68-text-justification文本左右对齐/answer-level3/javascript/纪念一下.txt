![QQ截图20190925171934.png](https://pic.leetcode-cn.com/5b44e5bedd2b2a1afc1499f28863d31d9ced8c5480c1188507cdf62bf5905293-QQ%E6%88%AA%E5%9B%BE20190925171934.png)

```
/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function(words, maxWidth) {
    let res = [''];
    for (let i = 0; i < words.length; i++) {
        putWord(res, words[i], maxWidth);
    }

    for (let j = 0; j < res.length; j++){
        if (j === res.length -1) {
            startFix(res, j, maxWidth)
        } else {
            spaceBetween(res, j, maxWidth)
        }
    }

    return res
};

/**
 * @param {string} word
 * @param {number} maxWidth
 * @param {string[]} result
 */
var putWord = function(result, word, maxWidth) {
    if (result[result.length - 1] === '') {
        result[result.length - 1] = word
    } else {
        if (result[result.length - 1].length + word.length + 1 <= maxWidth) {
            result[result.length - 1] = result[result.length - 1] + ' ' + word
        } else {
            result.push('')
            putWord(result, word, maxWidth)
        }
    }
}

/**
 * @param {string[]} result
 * @param {number} i
 * @param {number} maxWidth
 */
var spaceBetween = function(result, i, maxWidth) {
    let arr = result[i].split(' ');
    if (arr.length === 1) {
        startFix(result, i, maxWidth)
        return;
    }
    let evenSpace = Math.floor((maxWidth - result[i].length) / (arr.length - 1));
    let restSpace = (maxWidth - result[i].length) % (arr.length - 1);
    let evenStr = ''
    for (let i = 0; i < evenSpace; i++) {
        evenStr += ' '
    }
    for (let i = 0; i < arr.length - 1; i++) {
        if (i < restSpace) {
            arr[i] += evenStr + ' '
        } else {
            arr[i] += evenStr
        }
    }
    result[i] = arr.join(' ')
}

/**
 * @param {string[]} result
 * @param {number} i
 * @param {number} maxWidth
 */
var startFix = function(result, i, maxWidth) {
    let restSpace = maxWidth - result[i].length;
    for (let j = 0; j < restSpace; j++) {
        result[i] += ' '
    }
}
```

