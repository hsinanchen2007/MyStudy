### 解题思路
1.words里的单词分解成单个数组
2.判断每个数组是否都在chars里
3.如果都在就加上他的长度。
4.最后返回这个总长度
### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
let v=0
let temp=[]
let b=chars.split('')
let num=0
let total=0
for (let i = 0; i < words.length; i++) {
  var a= words[i].split('')
 for (let j = 0; j < a.length; j++) {
     if ( b.indexOf(a[j])!==-1) {
            b.splice(b.indexOf(a[j]),1)  
             num++
             if (words[i].length<=num) {
                 console.log(words[i]);  
                 console.log(num);  
                total+=num
             }
     }
 }
 num=0
 b=chars.split('')
}
return total
};
```