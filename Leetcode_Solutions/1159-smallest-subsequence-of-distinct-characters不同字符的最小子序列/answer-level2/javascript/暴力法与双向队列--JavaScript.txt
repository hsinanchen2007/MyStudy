按`字典序`排序： 去重后取最小的字典序的子序列

示例一中`"cdadabcc"` 的去重结果有`"cdab"`, `"cadb"`, `"dabc"`, `"adbc"`，最小的字典序为`"adbc"`

一、暴力法

通过递归找出所有的去重结果。

时间复杂度为O(n!),妥妥的超时！

```javascript []
  var chars = new Set(text)
  var list = new Set()

  function backtrack(sub, n) {
    if (sub.size === chars.size) return list.add([...sub].join(''))
    for (let i = n; i < text.length; i++) {
      const char = text[i]
      if (!sub.has(char)) {
        sub.add(char)
        backtrack(sub, i + 1)
        sub.delete(char)
      }
    }
  }

  backtrack(new Set(), 0)
```

二、双向队列

通过双向队列保存当前字母，当确认是最优解后增长子序列。

时间复杂度为O(n × m) 。n 为文本长度，m为子序列长度

1、当前字母正好的需要的，直接加入结果，清空队列

2、当前字母是最后一个时，将队列中比当前字母小的加入结果

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;
2.1、当前字母在队列中时，保留其余字母

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;
2.2、当前字母不在队列中时，清空队列

3、当前字母不在时队列，并删除队列中比当前字母的大的

![未命名文件.png](https://pic.leetcode-cn.com/34b595547f320857be92ff4a4bdc4b67bc3c834185092b9a65531cf6f4f130ef-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6.png)
```javascript []

var smallestSubsequence = function (text) {
  var map = {}, chars = [], result = '', queue = new Deque(), len // Deque 的实现在下面
  for (let char of text) {
    if (map[char]) {
      map[char]++
    } else {
      map[char] = 1
      chars.push(char)
    }
  }

  //排序后得到理想最优解
  chars.sort()
  len = chars.length

  function add(char) {
    result += char
    chars.splice(chars.indexOf(char), 1)
    map[char] = 0
  }

  for (let i = 0; result.length < len; i++) {
    const char = text[i]
    if (chars[0] === char) {
      // 正好的当前需要的，直接插入
      add(char)
      queue.clear()
    } else if (map[char] === 1) {
      // 将队列中比 char 小的插入, 
      while (queue.first < char) {
        add(queue.first)
        queue.shift()
      }
      // 如果 char 在队列中 ，保留比 char 大的，不在则删除比 char 大的
      if (queue.first === char) {
        add(char)
        queue.shift()
      } else {
        add(char)
        queue.clear()
      }
    } else if (map[char]) {
      map[char]--
      //  队列没有当前字母 char 时， 保留比 char 小的字母, 删除比 shar 大的字母
      if (!queue.has(char)) {
        while (queue.last > char) {
          queue.pop()
        }
        queue.push(char)
      }
    }
  }

  return result
};
```
附：简单的双向队列实现
```
class Deque extends Array {
  get first() {
    return this[0]
  }
  get last() {
    return this[this.length - 1]
  }
  clear() {
    this.splice(0, this.length)
  }
  has(val) {
    return this.indexOf(val) !== -1
  }
}
```