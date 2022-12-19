### 解题思路

把数组中每个字符串, 弄成数组, 检查第一个元素是否在chars中 存在就 从数组中删掉该字符, 同时chars中也删掉(每次只删一个字符)

碰到不存在的就打断循环, 

如果都存在 最后这个数组也就删完了, 长度就为0, 

不存在的话,最后这个数组肯定会剩下那些 在chars中没有的,

所以 最后剩下长度为0 的符合要求

```js
//如: words = ["cat","bt"], chars = "atach"

遍历数组 words

循环到 cat :
           首字母 c 存在于 'atach' 中  , 删除 此后 变为 'at' 'atah', 继续
                  a 存在 'atah'  ,       删除    变为 't'   'aah' , 继续
                  h 存在 'aah'           删除,  此时 长度为0 了, 符合要求, 记下 'cat'
循环到 bt :

          首字母 b  不存在 于 'atach' 中, 打断循环, 不符合要求,

words 遍历结束

      得到结果 'cat' , 长度为3
           
```


### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
  let res = ''
  words.forEach(item => {
    let str = chars
    let list = item.split('')
    while(list.length > 0) {
      let head = list[0]
      if(str.indexOf(head) > -1){
        list.shift()
        str = str.replace(head,'')
        continue
      }else{
        break;
      }
    }
    if(list.length === 0){
      res += item
    }
  })
  return res.length
};
```