```
var reverseWords = function (s) {
    let arr = s.trim().replace(/\s+/g, ' ').split(' ')
    let left = 0, right = arr.length - 1
    while (left < right) {
        [arr[left], arr[right]] = [arr[right], arr[left]]
        left++
        right--
    }
    return arr.join(' ')
};
```
