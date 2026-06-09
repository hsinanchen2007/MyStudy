**两个思路**

一种是 先按空格分成单词数组，每个单词元素重排

```javascript
var reverseWords = function(s) {
    return s.split(' ').map(item =>{
        return item.split('').reverse().join('')
    }).join(' ')
};
```
也可以用正则 s.split(/\s/g)

还可以用match word和' s.match(/[\w']+/g)

另一种思路是 把每个字母都颠倒过来，tsetnoc edoCteeL ekat s'teL ，然后按照空格再重新排序

```javascript
export default (str) => {
    return str.split('').reverse().join('').split(' ').reverse().join(' ')
}
```



