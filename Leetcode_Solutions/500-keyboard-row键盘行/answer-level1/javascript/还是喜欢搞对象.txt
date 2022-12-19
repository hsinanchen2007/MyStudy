### 解题思路

就是创建个对象 字母 为 属性, 值 为 所在的行数, 在同一行值就相同, 

直接筛选, 判断首字母在哪一行, 然后判断每个字符是否跟首字母值一致就行了

嘿嘿,这对象腿还挺长...

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {string[]}
 */
 var findWords = function(words) {
    let obj = {
      q:0,
      w:0,
      e:0,
      r:0,
      t:0,
      y:0,
      u:0,
      i:0,
      o:0,
      p:0,
      a:1,
      s:1,
      d:1,
      f:1,
      g:1,
      h:1,
      j:1,
      k:1,
      l:1,
      z:2,
      x:2,
      c:2,
      v:2,
      b:2,
      n:2,
      m:2
    }
    return words.filter(item => {
      item = item.toLocaleLowerCase()
      let num = obj[item[0]]
      return item.split('').every(t => obj[t] === num)
    })
  };
```