### 解题思路
滑动窗口问题，找一个区间内的最大值
左右各有一个临界值，不断的向右拓展
拓展的过程中，记录并比较最大值

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let max = 0;
    let l = 0, r = 0;
    let set = new Set();
    while(l < s.length && r < s.length){
        if(!set.has(s[r])){
            set.add(s[r])
            max = Math.max( max, set.size )
            r++;
        }else{
            set.delete(s[l])
            l++;
        }
    }
   return max
    
};
```