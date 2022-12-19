```
var addStrings = function(num1, num2) {
    let str ='';
    let carry = 0;
    let i = num1.length - 1;
    let j = num2.length - 1;
    while(i>= 0 || j >=0){
        let n1 = i>= 0?num1[i]-'0':0;
        let n2 = j>=0?num2[j]-'0':0;
        let to = n1+n2+carry;
        carry = parseInt(to/10);
        str = str+(to%10).toString();
        i--;
        j--;
        
    }
    
    if(carry == 1)  str = str+"1";
    return str.split("").reverse().join("");
    
};
```
