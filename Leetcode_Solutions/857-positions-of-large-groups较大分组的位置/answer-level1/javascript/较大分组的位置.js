*法一：双指针*

```js
var largeGroupPositions = function(S) {
    let left = 0;
    let right = 1;
    let arr = [];
    let len = S.length;
    while(right < len) {
        if (S[left] === S[right]) {
            right++;
        } else {
            if (right - left >= 3) {
                arr.push([left, right-1])
            }
            left = right;
        }
    }
    if (right - left >= 3) {
        arr.push([left, right-1])
    }
    return arr
};
```

*法二：正则*

```js
var largeGroupPositions = function(S) {
    const pat = /(\w)\1{2,}/g
    let arr = [];
    let item;
    while((item = pat.exec(S)) !== null) {
        arr.push([item.index, item.index + item[0].length - 1])
    }
    return arr
};
```

