
循环递减，在循环中判断相加是否为10，如果为10，就把当前值改为0，下一值加一；如果三位数加一变4位数的话，就给数组unshift(1)

执行用时：72 ms
```
var plusOne = function(digits) {
    for(let i=digits.length-1;i>=0;i--){
        if(i==digits.length-1){
            digits[i]++
        }
        if(digits[i]==10){
            digits[i]=0
            if(i-1<0){
                digits.unshift(1)
            }else{    
                digits[i-1]++
            }
        }
    }
    return digits
};
```

