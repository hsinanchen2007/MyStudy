
![javascript.jpg](https://pic.leetcode-cn.com/9978e712a3da44f824658cdd2926aa330e7a1050893b56813a932a39d64ad08d-javascript.jpg)

<br />

## javascript 奇思妙想版解法 (平均耗时140ms, 平均性能42MB)

<br />

```js
let countBinarySubstrings = function (s) {
  let n = 0, arr = s.match(/([1]+)|([0]+)/g)
  for (let i = 0; i < arr.length - 1; i++) {
    n += Math.min(arr[i].length, arr[i + 1].length)
  }
  return n
}
```

<br />

因为已知
- `000111`必定有三个子串
- `00011`必定有两个子串
- `0111`必定有1个子串
以此类推, 每两组数据之间长度最短的值为子串的数量

> 然后我对比别人的答案发现, 发现无论是性能还是耗时都不如别人, 伤心....

<br />

## javascript 大众版解法 (平均耗时100ms, 平均性能37MB)

<br />

```js
let countBinarySubstrings = function (s) {
  let n = 0, pre = 0, curr = 1
  for (let i = 0, len = s.length; i < len - 1; i++) {
    if (s[i] == s[i+1]) {
      curr++
    } else {
      pre = curr
      curr = 1
    }
    if (pre >= curr) n++
  }
  return n
}
```
