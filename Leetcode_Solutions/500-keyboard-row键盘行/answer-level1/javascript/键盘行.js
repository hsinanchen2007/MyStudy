
// 正则匹配

// ```js
var findWords = function(words) {
    var pattern = /^([qwertyuiop]+|[asdfghjkl]+|[zxcvbnm]+)$/i;
    return words.filter((item) => {
        return pattern.test(item)
    })
};
// ```

