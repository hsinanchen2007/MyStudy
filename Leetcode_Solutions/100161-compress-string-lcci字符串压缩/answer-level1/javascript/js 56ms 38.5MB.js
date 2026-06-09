### 解题思路
![image.png](https://pic.leetcode-cn.com/89c95f051e18db4cd4f1753fa1624f1ee309c5d2bd77df3bf609f141e6732507-image.png)

一次遍历

引入一个记录结果的res变量，和记录下标位置的t变量

思路很简单，就是当前遍历的和前一个不相等的话就要改变res

注意点：最后还要将(i-t)加入res字符串中，因为最后一个字符退出了循环加入不了数量

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
  let len = S.length
  if (len < 3) return S
  let res = ''
  res += S[0]
  let t = 0
  for (var i = 1; i < len; i++) {
    if (S[i] !== S[i-1]) {
        res += (i-t)
        t = i
        res += S[i]
    }
  }
  res += (i-t)
  
  return res.length < len ? res : S
};
```