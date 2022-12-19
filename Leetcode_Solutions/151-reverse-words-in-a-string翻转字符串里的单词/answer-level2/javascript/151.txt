### 解题思路
这个主要想着通过原生数组方法就可以完成的了，主要是split后要对空字符串进行数据清洗，然后reverse后 重新jion 就可以了

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (str){
  
   return str.split(' ').filter(el=>{
        return el !== ''
    }).reverse().join(' ');
  
}
```