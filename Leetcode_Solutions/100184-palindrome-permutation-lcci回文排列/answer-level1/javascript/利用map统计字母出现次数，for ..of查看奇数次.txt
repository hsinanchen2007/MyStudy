### 解题思路
中心思想：统计每个字符出现的次数，奇数次只能出现一次

### 代码
![image.png](https://pic.leetcode-cn.com/71e58c8d4b5d42c9f3e4fc5efaafbe133db610c0e18232c30f164afcfe4c160e-image.png)

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var canPermutePalindrome = function(s) {
   let m = new Map()
   let count =0;
   for(let i = 0;i<s.length;i++){
       if(m.has(s[i])){
           let count = m.get(s[i])+1
           m.set(s[i],count)
       }else{
           m.set(s[i],1)
       }
   }
   m.forEach((value,key)=>{
       if(value%2 === 1){
           count++;
       }  
   })
   return count < 2? true : false
};
```