### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let i=digits.length-1;
    while(i>=0){
        digits[i]=digits[i]+1;
        if(digits[i]!=10){
            return digits;
        }
        digits[i]=0;//此时digits=10，则将该位只设置为0，继续向前进位
        i--
    }
    digits.unshift(1);//如果执行到这一步，说明999...99类型的，并且现在全部变为000..00了，则只需再头部添加1即可
    return digits;
};
```