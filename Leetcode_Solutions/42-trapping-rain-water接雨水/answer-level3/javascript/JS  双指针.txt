
### 代码

> #### 时间复杂度：O(n)    空间复杂度：O(1)

```javascript
var trap = function(arr) {
    let left = 0
    let right = arr.length - 1
    let res = 0
    let left_max = 0
    let right_max = 0
    while (left < right) {
        if (arr[left] < arr[right]) {
            if (arr[left] >= left_max) {
                left_max = arr[left]
            }
            res += (left_max - arr[left])
            left++
        } else {
            if (arr[right] >= right_max) {
                right_max = arr[right]
            }
            res += (right_max - arr[right])
            right--
        }
    }
    return res
};
```