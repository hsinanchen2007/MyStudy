```js
var reverseWords = function(s) {
    let arr = s.split(' ');
    let arr2 = [];
    for(let i = 0; i < arr.length; i++) {
        arr2.push(arr[i].split('').reverse().join(''))
    }
    return arr2.join(' ');
};
```


