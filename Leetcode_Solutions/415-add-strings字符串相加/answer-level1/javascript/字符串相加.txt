### 解题思路
1. 将较短的字符串在头部用 0 补齐，这里用到了 `padStart` 方法；
2. 从字符串尾部开始相加，如果大于 `9`，则向前进一位，用于下次计算；
3. 计算完之后如果仍然有进位，则 `unshift` 进数组；
4. 最后将数组转位字符串返回。
### 代码

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    let num1Len = num1.length;
    let num2Len = num2.length;
    let diffLen = num1Len - num2Len;
    if(diffLen > 0){
        num2 = num2.padStart(Math.abs(diffLen) + num2Len,'0');
    }else{
        num1 = num1.padStart(Math.abs(diffLen) + num1Len,'0');
    }
    const { length } = num1;
    let result = [];
    let temp = 0;
    for(let i = length - 1; i >= 0; i--){
        let sum = Number(num1[i]) + Number(num2[i]) + temp;
        if(sum > 9){
            sum = sum % 10;
            temp = 1;
        }else{
            temp = 0;
        }
        result.unshift(sum);
    }
    if(temp>0){
        result.unshift(temp);
    }
    return result.join('');
};
```