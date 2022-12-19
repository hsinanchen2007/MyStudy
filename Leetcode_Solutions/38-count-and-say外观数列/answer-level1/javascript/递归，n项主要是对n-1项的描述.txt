主要是num的计数，每次重复的字符处理完毕后，将num置为1，重新开始判断字符的重复次数

### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    if( n==1 ) return '1'
    let newStr = ''
    // n-1 的 观察数列
    let lastStr = countAndSay(n-1)
    // 考察 n-1 项的每一个字符，num为当前考察字符重复的字数
    let num = 1
    for(let i = 0 ; i< lastStr.length; i++){
        if(lastStr[i] == lastStr[i+1]){
            num ++ 
        }else{
            newStr += num
            newStr += lastStr[i]
            num = 1
        }
    }
    return newStr
};
```