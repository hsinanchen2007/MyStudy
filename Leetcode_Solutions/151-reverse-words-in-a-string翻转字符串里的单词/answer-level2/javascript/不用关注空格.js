### 解题思路

不用关注空格, 用split切割 同样会吧空格切出来
```js
 // 如 s = "   hello   world!  " 会得到 ["", "", "", "hello", "", "", "world!", "", ""]
  // 再用filter 筛选出不是空格的后 翻转 转成字符串就行了
```

![image.png](https://pic.leetcode-cn.com/022afdc1c4d634dba05a034d36e1a68835596871df0bfb960f54b7cc97455c8f-image.png)

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
  return s.split(' ').filter(item => item).reverse().join(' ')
};
```


如果不用现有的api, 可以只用循环

```js
 var reverseWords = function(s) {
  let list = [], str = '', resStr = ''
  s += ' '   // 加个空格 防止最后一个不是空格的情况, 确保循环到最后能把最后一个加到数组中, 省得再在下面判断
  for(let i = 0; i < s.length; i++){
    s[i] !==' ' ? str += s[i] : str && (list.push(str),(str = ''))
  }
  for(let j = list.length - 1; j >= 0; j--){
    resStr += j !== 0 ? list[j] + ' ' : list[j]
  }
  return resStr
};
```