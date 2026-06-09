### 代码

```javascript

var reverseWords = function(s) {
    let res = s.split(' ')
               .filter(item => Boolean(item))
               .map(item => String.prototype.trim.call(item))
               .reverse()
               .join(' ')
    return res
};

```