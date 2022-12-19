### 解题思路
&emsp;&emsp;题解思路写在注释里了
### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var translateNum = function(num) {
    /**
     *  dp[i] = 前i个字符能有多少种翻译 
     *  联合翻译前一个字母必是1或者2，如果是2第二个字符不能大于5
     *  a表示 i - 1 的状态, b表示 i - 2 的状态（进行了状态压缩）
     */
    if(num < 10) return 1;
    let numStr = new String(num),
        a = b = 1;
    for(let i = 2; i <= numStr.length; i++){
        if(numStr[i - 2] == '1' || (numStr[i - 2] == '2' && numStr[i - 1] <= '5')){
            [a, b] = [a + b, a];
        }else{
            b = a;
        }
    }
    return a;
};
```