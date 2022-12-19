双指针，对撞指针。

```js
var reverseString = function(s) {
    let right = 0
    let left = s.length - 1
    while(right < left) {
        [s[right], s[left]] = [s[left], s[right]]
        right++
        left--
    }
};
```