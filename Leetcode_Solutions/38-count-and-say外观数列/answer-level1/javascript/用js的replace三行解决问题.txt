```
var countAndSay =n=> {
    var s="1"
    while(--n)s=s.replace(/(.)\1*/g,(m,d)=>m.length+d)
    return s
   
};
```
就是这么简单清晰..
