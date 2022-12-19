### 解题思路

![image.png](https://pic.leetcode-cn.com/166df1a94c7221bcba2e99a602f6c0c9c4c759d8d1e569f232eb10a8503d3d03-image.png)

- 三角形定理，任意两边之和大于第三边
- 延伸，最小的两边之和大于第三边即可。

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var largestPerimeter = function(A) {
    A = A.sort((a,b) => a - b)
    let len = A.length
    let res = 0
    for(let i = len - 1; i > 0; i--){
        if(A[i-1] + A[i-2] > A[i]){
            return res = A[i-1] + A[i-2] + A[i]
        }
    }
    return 0
};
```