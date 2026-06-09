![image.png](https://pic.leetcode-cn.com/9515276ee2ac3ffa8ffe42e57f8ea0b87b7de139322f0449e583cafbfd606529-image.png)

```
var plusOne = function(digits) {
    if(digits[digits.length-1] < 9) {
        digits[digits.length-1] += 1;
        return digits;
    }
    for(let i = digits.length-1;i>=0;i--){
        digits[i]++;
        if(digits[i] == 10) {
            digits[i] = 0; 
        }else{
            return digits;
        }
    }
    digits.unshift(1);
    return digits;
};
```
