### 解题思路
滑动窗口：保证窗口中一直最多只有三个0

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var longestOnes = function(A, K) {
    var left=right=count=max=0;
    while(right<A.length){
        if(A[right]==0){
            count++;
        }
        while(count>K){
            if(A[left]==0){
                left++;
                count--;
            }else{
                left++;
            }
        }
        max = Math.max(max,right-left+1);
        right++;
    }
    return max;
};
```