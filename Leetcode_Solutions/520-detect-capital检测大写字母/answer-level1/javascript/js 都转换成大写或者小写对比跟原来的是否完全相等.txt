### 方法一
正则，简单明了但是比较耗时。

```javascript
var detectCapitalUse = function(word) {
    let reg1 = /^[A-Z]*$/;
    let reg2 = /^[A-Z][a-z]*$/;
    let reg3 = /^[a-z]*$/;
    return reg1.test(word) || reg2.test(word) || reg3.test(word);
};
```

### 方法二
时间上稍微快一点，思路：
看字符串完全大写或者小写之后是否跟原来的相同，相同则说明字符串是全都大写或者小写的。
若是不相同，那说明字符串中有大写也有小写。首先判断是否是首字母大写，若首字母大写了那判断后面的字母是否全都是小写。
![image.png](https://pic.leetcode-cn.com/744d7406a0b3559c0d187f382a19b74bcf9806c2f37e4acbe5b03116d7ed6947-image.png)
```javascript
var detectCapitalUse = function(word){
    if(word.toUpperCase() == word || word.toLowerCase() == word) return true;
    let first = word[0];
    if(first!==first.toUpperCase()) return false;
    else{
        word = word.split('').splice(1).join('');
        if(word.toLowerCase() == word) return true;
        else return false;
    }
}
```