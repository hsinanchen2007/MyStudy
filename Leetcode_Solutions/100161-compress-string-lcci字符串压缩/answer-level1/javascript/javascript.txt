```
let s='';
  let count=1;
  for(let i=1;i<S.length;i++){
    if(S[i]==S[i-1]){
      count++
    }else{
      s+=S[i-1]+count;
      count=1;
    }
  }
  s+=S[S.length-1]+count;
  return S.length>s.length?s:S
```
