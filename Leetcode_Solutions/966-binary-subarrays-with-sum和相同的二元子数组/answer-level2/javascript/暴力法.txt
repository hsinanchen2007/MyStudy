### 解题思路
遍历数组，加到和为S的时候停止

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} S
 * @return {number}
 */
var numSubarraysWithSum = function(A, S) {
//   let result = []
//   for(let i = 0;i<A.length;i++) {
//       let count = 0
//       let init = i
//       while(count<=S) {
//           count+=A[i]
//           i++
//           if(count === S) {
//               result.push(A.slice(init,i))
//           }
//       }
//       i = init
//   }
//   return result.length
     let result = 0
     for(let i = 0;i<A.length;i++) {
        let count = 0
        let sum = 0
        while(sum<=S){
          sum+=A[i+count]
          count++
          if(sum==S) result++
        }
     }
     return result
};
```