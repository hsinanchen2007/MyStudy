### 解题思路
因为是子串，并不是子序列，所以思考难度低了很多，
首先肯定需要把字符串扫一遍，在扫描过程中跟踪子串的变化，
如果当前元素跟子串中元素重复，则它在子串中对应的 index 为断点，此时可以更新最长长度的大小，
同时需要将断点前的所有元素清除，然后推入当前元素，将子串刷新，重新开始增长，
遍历完最后还需要再比较一次最长长度和子串长度，因为子串后续无断点的话，会一直增长，有可能超过之前记录的最长长度。

题外话：很多算法题都只要求长度， 并不要求对应的序列或者子串，所以这题不需要记录遍历过程中产生的子串，只需要对应的长度即可。
之前也找出了最长子串，但是内存占用多了一倍。
如果观察子串的变化，应该是这样的：
```
输入："abcdbcbb"

子串变化：
[ [ 'a', 'b', 'c', 'd' ], // 一直增长
  [ 'c', 'd', 'b' ], // 遇到 b，重复，移除 b 前面的元素，加入 b
  [ 'd', 'b', 'c' ], // 遇到 c，重复，移除 c 前面的元素，加入 c
  [ 'c', 'b' ], // 同上
  [ 'b' ] ] // 同上
```
可以发现子串越来越小，所以必须对最长子串有个记录，此题是求长度，因此不需要跟踪最长子串的内容变化，记录长度即可。


### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let longestLen=0;
    let tmpsubstr=[];
    for(let i=0, len=s.length;i<len;i++){
        let breakpoint= tmpsubstr.indexOf(s[i]);
        let tmpLen = tmpsubstr.length;
        if(breakpoint>-1){ // 遇到断点
            longestLen= longestLen > tmpLen ? longestLen : tmpLen;
            tmpsubstr=tmpsubstr.slice(breakpoint+1); // 移除左侧所有元素
        }
        tmpsubstr.push(s[i]);
    }
    return longestLen > tmpsubstr.length
             ? longestLen 
             : tmpsubstr.length;;
};
```