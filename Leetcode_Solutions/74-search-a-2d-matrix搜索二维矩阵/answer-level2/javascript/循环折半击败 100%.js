![image.png](https://pic.leetcode-cn.com/3d8e591267ed8766f49ce95bfa0a162b49c261a609b03eb4ca71861e74a35972-image.png)


### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    if (!matrix.length || !matrix[0].length) return false;

    for(let i = 0; i < matrix.length; i++) {
        let arr = matrix[i];
        let low = 0;
        let high = arr.length - 1;

        if (target < arr[low]) return false;

        if (target <= arr[high]) {
            while(low <= high) {
                let mid = Math.floor(low + (high-low) /2 );
                if (arr[mid]> target) {
                    high = mid - 1;
                } else if (arr[mid] < target) {
                    low = mid + 1;
                } else {
                    return true;
                }
            }
            return false;
        }
    }

    return false;
};
```