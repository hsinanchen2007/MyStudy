### 解题思路
- 双指针方法，通过 left 和 right 进行判断；
- 整体做一次循环遍历，如果发现前后先相同元素相同，继续下一次遍历；
- 如果发现不同，先进行判断，如果间隔大于等于3，则加入数组；
- 最后再做一次判断；

### 代码

```javascript
/**
 * @param {string} S
 * @return {number[][]}
 */
var largeGroupPositions = function(S) {
    let left = 0
    let right = 1
    let len = S.length
    let arr = []
    while(right < len) {
        if (S[left] === S[right]) {
            right++
        } else {
            if (right - left >= 3) {
                arr.push([left, right - 1])
            }
            left = right
        }
    }
    
    if (right - left >= 3) {
            arr.push([left, right - 1])
    }
    return arr
};
```