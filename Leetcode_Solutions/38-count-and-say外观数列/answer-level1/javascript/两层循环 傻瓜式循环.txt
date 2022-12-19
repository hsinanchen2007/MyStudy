### 解题思路
把数字转换成字符串思考
给定范围1<=n<=30 自己往下演算几遍就得出最多存在3这个数字
思路就是重复n次就加n字符串 + 重复的值
只写到了3
### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
   if (n ===1 ) return '1'
    let value = '1'
    let str =''
    while(n>1){
        let str =''
        for(let i =0;i<value.length;i++){
            if(i+1<value.length && value[i] === value[i+1] ){
                if(i+2<=value.length && value[i+1] === value[i+2]){
                    str= str + '3'+value[i]
                    i+=2
                }else{
                    str= str + '2'+value[i]
                    i++
                }
            }else{
                str = str+'1'+value[i]
            }
        }
        n--
        value = str
    }
    return value
}
```