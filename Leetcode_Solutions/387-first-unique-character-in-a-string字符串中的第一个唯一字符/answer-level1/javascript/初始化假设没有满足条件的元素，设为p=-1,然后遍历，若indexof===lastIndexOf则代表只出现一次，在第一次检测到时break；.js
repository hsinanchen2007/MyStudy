```javascript []
let p=-1;
    for(let i = 0;i<s.length;i++){
    if(s.indexOf(s[i])==s.lastIndexOf(s[i])){
        p=i;
        break;
    }
}
    return p;
```
