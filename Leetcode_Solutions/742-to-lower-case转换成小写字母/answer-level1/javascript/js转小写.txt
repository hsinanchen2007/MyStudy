### 解题思路
首先题目没规定说不能用内置函数,所以可以直接使用内置函数
### 代码

```javascript
/**
 * @param {string} str
 * @return {string}
 */
var toLowerCase = function(str) {
    return str.toLocaleLowerCase()
};
```

其次,就是使用ASCII码转换, A-Z => 65-90  a-z => 97-122 大小写之间的码相差32, js中字母字符串转ASCII使用  字母.charCodeAt(), 码转字母使用 String.fromCharCode(码数)
```
var toLowerCase = function(str) {
    let res = ''
    for(let item of str){
      let ch = item.charCodeAt()
      if(ch>=65&&ch<=90){
        res += String.fromCharCode(ch + 32)
      }else{
        res += item
      }
    }
    return res
};
```
最后,就是连ASCII码都不知道是什么鬼的,前端涉及比较少这方面的,就可以使用比较笨的方法,使用一个对象存放对应的大小写,然后遍历一一对应
```
var toLowerCase = function(str) {
    let obj = {
      'A':'a',
      'B':'b',
      'C':'c',
      'D':'d',
      'E':'e',
      'F':'f',
      'G':'g',
      'H':'h',
      'I':'i',
      'J':'j',
      'K':'k',
      'L':'l',
      'M':'m',
      'N':'n',
      'O':'o',
      'P':'p',
      'Q':'q',
      'R':'r',
      'T':'t',
      'S':'s',
      'U':'u',
      'V':'v',
      'W':'w',
      'X':'x',
      'Y':'y',
      'Z':'z'
    }
    let list = str.split('')
    list.forEach((item,index) => {
      if(obj[item]){
        list[index] = obj[item]
      }
    })
    return list.join('')
};
```

