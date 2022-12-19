因为每位表示一个数字，所以数组每个值得范围都在0-9，一旦+1 等于10，这个数就归零，在他前面的数+1，一直到第一个数若为10则变成[1,0]
```
digits[digits.length-1]++;
    for(let i=digits.length-1;i>=0;i--){
        if(digits[i] === 10){
            if(i-1>=0){
                digits[i-1]++;
                digits[i] = 0
            }else{
                digits.splice(0,1);
                digits =[1,0].concat(digits)
            }
        }
    }
    return digits
```
