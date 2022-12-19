
```
var addDigits = function(num) {
    if(num<10) return num;
    num+='';
    let arr = num.split('');
    let netNum = 0;
    arr.forEach(item=>{
           netNum+=Number(item)
    })
    return addDigits(netNum); 
    
};
```

