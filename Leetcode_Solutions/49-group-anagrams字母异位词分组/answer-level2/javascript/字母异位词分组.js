- 对字母字符串进行排序
- 用哈希表存下每个排序后的字符串
```javascript
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
   if(!strs || !strs.length) return strs;
   let map = new Map();
   let ans = [];
   for(let str of strs) {
       let key = str.split('').sort().join(); // sort还可以排序字符串、学到了
       if(!map.has(key)) {
           map.set(key,[str]);
       } else {
           let temp = map.get(key)
           temp.push(str);
           map.set(key,temp);
       }
   }
   for(const val of map.values()) {
       ans.push(val);
   }
   return ans;
};
```
时间复杂度：O(nklogk),n是strs的长度,k是字符串长度，for循环的时间复杂度O(n)，sort的时间复杂度O(klogk)
空间复杂度: O(n),用哈希表存储了每个值
