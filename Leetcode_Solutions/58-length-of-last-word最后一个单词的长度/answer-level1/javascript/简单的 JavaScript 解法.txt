### 解题思路
直接使用 while 跳过最后的所有空格即可

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    if(!s.length) return 0;
    let count = 0;
    let i = s.length - 1;
    while(s[i] == ' '){
        i --;
    }
    for(; i >= 0; i--){
        if(s[i] != ' '){
            count++;
        }else{
            break;
        }
    }

    return count;
};
```