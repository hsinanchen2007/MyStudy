### 解题思路
1、定义起始下标start，循环遍历i，最长子串长度max，用来检索重复字符的cache，以及字符串长度len，避免每次循环时读取length
2、特殊情况判断
3、缓存第一个下标元素，从第二个下标开始遍历，依次判断是否包含在缓存内，是，则往后移动下标，移动的到重复的元素（两个，选前面那个）所在下标
4、更新缓存，如果【下标元素到当前遍历到的元素】的长度比max大，则更新max的值

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var lengthOfLongestSubstring = function(str) {
  let start = 0, i, max = 0, cache = '', len = str.length;
  
  if(!str)return 0;
  if(str.length == 1)return 1;
  // 用来检索重复字符
  cache = str[0];
  max = 1;

  for (i = 1; i < len; i++) {
    // 有重复字符
    if (cache.indexOf(str[i]) > -1 ){
      // 往后移动下标
      start = cache.indexOf(str[i]) + 1 + start;
    }
    cache = str.substring(start, i + 1);
    max = i - start + 1 > max ? i - start + 1 : max;
  }
  return max;
};
```