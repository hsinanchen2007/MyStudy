```javascript []
    for(let i=0;i<s.length;i++){
        if(i<s.length-1-i){
           [s[i],s[s.length-1-i]]=[s[s.length-1-i],s[i]]
        }
    }
    return s
```

