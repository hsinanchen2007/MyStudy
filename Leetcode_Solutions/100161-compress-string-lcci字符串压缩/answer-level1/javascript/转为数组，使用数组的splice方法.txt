### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
//   let length = S.length
//   let ans = ''
//   let i =j=0
//   while(j<length-1) {
//       if(S[j]!==S[j+1]) {
//           ans+=S[i] +(j-i+1)
//           i=j+1
//       }
//       j++
//   }
//   ans+=S[i] +(j-i+1)
//   return ans.length>=length?S:ans
     let arr = S.split('')
     for(let i = 0;i<arr.length;i+=2) {
         let j = i
         while(arr[j] === arr[i]) j++
         arr.splice(i+1,j-i-1,j-i)
     }
     let ans = arr.join('')
     return ans.length<S.length?ans:S
};
```