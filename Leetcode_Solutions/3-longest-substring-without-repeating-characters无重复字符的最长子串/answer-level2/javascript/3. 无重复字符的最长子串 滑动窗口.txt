# [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

## 效率

一共三种方法，其中有打败 90% 的方法。

## 思路

还是一遍循环解决，从前向后推，才发现这样的思路名词叫做“滑动窗口”。

## 解法

### 1、字符串

效率一般但容易理解：内存消耗大概 39.6MB，打败 55%；时间大概 92ms 左右，打败 87%。

```javascript
var lengthOfLongestSubstring = function(s) {
  let max = 0
  let str = ''
  for(let i = s.length - 1; i > -1; i--) {
    const ch = s[i]
    const index = str.indexOf(ch)
    if (index > -1) {
      if (str.length > max) max = str.length
      str = str.substr(index + 1)
    }
    str += ch
  }
  if (str.length > max) max = str.length
  return max
}
```


### 2、Map + 计数

在字符串的想法上改进。内存消耗降低至 37.5MB，打败 90%，执行时间常在 90ms 下，打败 90%，推荐：

> 从  《[javascript 解析思路 滑动字符串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/cyu-yan-shuang-yi-bai-by-wu-sheng-23/ )》 得到的计数思路

```javascript
var lengthOfLongestSubstring = function(s) {
  let max = 0
  let count = 0
  let map = new Map()
  for(let i = s.length - 1; i >= 0; i--) {
    const ch = s[i]
    if (map.get(ch) <= i + count) {
      if (count > max) max = count
      count = map.get(ch) - i
    } else {
      count++
    }
    map.set(ch, i)
  }
  if (count > max) max = count
  return max
};
```

### 3、数组

内存消耗大概 36.1MB，内存消耗打败 100%，时间平均 100ms 往上：

> 查看题解 《[js 最简单的队列思路，一目了然](<https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/js-zui-jian-dan-de-si-lu-yi-mu-liao-ran-by-chris-9/>  )》，做了一些修改 `const ch = s[i]` ，从 99% 提升到了 100%

```javascript
var lengthOfLongestSubstring = function(s) {
  let res = 0
  let i = 0
  let temp = []
  while(i < s.length) {
    const ch = s[i]
    if(temp.indexOf(ch) === -1) {
      temp.push(ch)
    } else {
      temp.shift()
      continue
    }
    res = Math.max(res, temp.length)
    i++
  }
  return res;
};
```
