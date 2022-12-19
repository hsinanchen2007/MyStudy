简单粗暴的方法，效率最高，内存最小
```javascript []
var compressString = function(S) {
    let count=1;
    let str = new String() ;
    for(let i = 1 ; i < S.length+1 ; i++){
        if(S[i-1] === S[i]){
            count++
        }else{
            str +=S.slice(i-1,i )+ count
            count = 1
        }
    }
    return S.length > str.length ? str : S
};

```


