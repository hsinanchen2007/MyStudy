### 解题思路
想到的是用' '空格分割string
注意点是'' ' '用分隔符分别产出的是[''],['','']
去除掉无用'' 返回最后一个单词长度即可

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let str = s.split(' ')
    let i =str.length-1
    while(i>=0){
        if(str[i]){
            return str[i].length
        }
        i--
    }
    return 0
};
```