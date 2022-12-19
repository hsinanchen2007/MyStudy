### 代码

```javascript
var reverseVowels = function(s) {
    const set = new Set(['a','e','i','o','u','A','E','I','O','U'])
    const arr = s.split('')
    let low = 0
    let high = arr.length - 1
    while (low < high) {
        if (set.has(arr[low])) {
            if (set.has(arr[high])) {
                [arr[low], arr[high]] = [arr[high], arr[low]]
                low++
            }
            high--
        } else {
            low++
        }
    }
    return arr.join('')
};
```
时间复杂度：O(n)
空间复杂度：O(2n)