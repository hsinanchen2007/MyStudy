```js
var longestPrefix = function(s) {
    let begin = s.slice(0, -1);
    let end = s.slice(1);

    while (true) {
        if (begin.length == 0 || end.length == 0) {
            return "";
        }
        if (begin === end) {
            return begin;
        }
        begin = begin.slice(0, begin.length - 1);
        end = end.slice(1);
    }
};
```