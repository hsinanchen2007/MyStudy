### 解题思路
数组从后向前遍历，对应到数字位数即为从低位向高位遍历，加1时大于9就将此位置为0，然后进行下一位判断，如果下一位小于等于9则++，并返回数组，其中特殊处理了首位大于9的情况，在原有数组增加首项1，并返回数组。
### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
// 使用数组 从后向前计算
var plusOne = function(digits) {
    // 数组倒序遍历 即由数字低位向高位的顺序
    for(let i = digits.length - 1; i >= 0; i--){
        let item = digits[i];
        // 加1 是否需要进位
        if(item + 1 > 9){
            // 需要进位的置 0 
            digits[i] = 0;
            // 判断该项是否为第一项
            if(i == 0){
               // 数组首项置1
               digits.unshift(1);
               return digits;
            }
        }else{
            // 不需要进位的直接加1
            digits[i]++;
            return digits;
        }
    }
};
```