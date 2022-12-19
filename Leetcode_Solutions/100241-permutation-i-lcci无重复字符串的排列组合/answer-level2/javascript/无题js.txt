```
var permutation = function(S) {
    var res=[];
    let len=S.length;
    //var visit=new Array(len).fill(0);
    (dfs=(str,visit)=>{
        if(str.length==len){
            res.push(str);
            return;
        }
        for(let i=0;i<len;i++){
            if(str.indexOf(S[i])!=-1) continue;
            str+=S[i];
            dfs(str);
            str=str.slice(0,str.length-1);
        }
        
    })('');
    
    return res;
}; 
```
