### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
   let longestNum = 0, list = [];
   for(let i = 0; i<s.length; i++){
       if(list.indexOf(s[i])===-1){
           list.push(s[i]);
       } else {
           list = list.slice(list.indexOf(s[i])+1);     //当有重复元素出现时，滑动窗口至改元素在list中出现位置的下一位
           list.push(s[i]);
       }
       longestNum = longestNum > list.length ? longestNum : list.length;
   }
   return longestNum;
};
```