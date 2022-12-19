### 解题思路

思路清晰，叫我第一，快排系列

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    if(arr.length == 0 || k == 0) return []
    quickSort(arr, 0, arr.length - 1)
    return arr.slice(0, k)
};

function quickSort(arr, begin, end){
    if(begin >= end) return

    let h = begin,
        target = end
    
    end--
    
    while(h <= end){
        if(arr[h] >= arr[target]){
            [arr[h], arr[end]] = [arr[end], arr[h]]
            end--
        } else {
            h++
        }
    }

    [arr[h], arr[target]] = [arr[target], arr[h]]

    quickSort(arr, begin, h-1)
    quickSort(arr, h+1, target)
}
```