/**
 * @param {number[]} A
 * @return {number}
 */
```javascript
var partitionDisjoint = function(A) {
            // 创建一个数组 arr[i] 代表着 (A[i]~A[len-1]中的最小值)
            const arr = [],len=A.length
            let tempMin = A[len-1]
            for(let i = len-1; i>=0;i--){
                if(A[i]<tempMin){
                    tempMin = A[i]
                }
                arr[i] = tempMin
            }

        // 依次遍历数组 如果左边的最大数小于右边最小值  则 找到分割点
            let leftMax = A[0] // 左边最大的数
            for(let i=0; i<len; i++){
                const num = A[i]
                
                // 更新 leftMax
                if(num > leftMax) leftMax = num
                
                if(A[i+1]!==undefined){
                    // 判断是否为最终结果
                    if(leftMax <= arr[i+1]){
                        return i+1
                    }
                }else{
                    return len
                }
            }
  };
```
