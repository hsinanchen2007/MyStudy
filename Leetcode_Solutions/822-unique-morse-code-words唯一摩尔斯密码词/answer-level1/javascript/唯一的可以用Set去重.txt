### 解题思路
此处撰写解题思路
题目给的那串码 一一对应 a-z , ASCII码对应(97-122), 遍历拿到每个单词, 根据单词的ASCII码值-97 得到索引,进而得到对应的摩尔斯密码, 拼接起来, 把他们放到一个数组, 最后用Set 去重, 返回它的长度即可
### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function(words) {
    
    let list = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    let arr = []
    words.forEach(item=>{
      let a = item.split('')
      let str = ''
      a.forEach(subItem=>{
        let index = subItem.charCodeAt()
        str += list[index-97]
      })
      arr.push(str)
    })
  return [...new Set(arr)].length

};
```

然后还有种比较费力的方法, 要手动创建个对象
```js 
var uniqueMorseRepresentations = function(words) {
   
   let obj = {
     a: ".-",
     b: "-...",
     c: "-.-.",
     d: "-..",
     e: ".",
     f: "..-.",
     g: "--.",
     h: "....",
     i: "..",
     j: ".---",
     k: "-.-",
     l: ".-..",
     m: "--",
     n: "-.",
     o: "---",
     p: ".--.",
     q: "--.-",
     r: ".-.",
     s: "...",
     t: "-",
     u: "..-",
     v: "...-",
     w: ".--",
     x: "-..-",
     y: "-.--",
     z: "--.."
   }
  let arr = []
   words.forEach(item=>{
     let a = item.split('')
     let str = ''
     a.forEach(subItem=>{
       str += obj[subItem]
     })
     arr.push(str)
   })
  return [...new Set(arr)].length
};
```
