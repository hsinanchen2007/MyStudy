### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @param {character} C
 * @return {number[]}
 */
  var shortestToChar = function (S, C) {
    let len = S.length
    let list = Array(len)
    let pre = S.indexOf(C)           // 记录首次出现C的索引
    for (let i = 0; i < len; i++) {  // 顺着遍历
      if (S[i] === C) {              // 当遍历到C的时候,更新pre
        pre = i       
      }
      list[i] = Math.abs(pre - i)    // 把差值存到list
    }


    let last = S.lastIndexOf(C)          // 记录最后一次出现C的索引
    for (let j = len - 1; j > 0; j--) {  // 逆着遍历
      if (S[j] === C) {                  // 当遍历到C的时候,更新last
        last = j
      }
      list[j] = Math.min(Math.abs(last - j), list[j])   // 对比前后两次谁最小,取最小
    }

    return list
  };
```