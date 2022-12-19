```
/**
 * @param {string} s
 * @return {string[]}
 */
var permutation = function(S) {
    var res=[];
    let len=S.length;
    var visit=new Array(len).fill(0);
    var map=new Map();
    (dfs=(str,visit)=>{
        if(str.length==len){
            if(map.has(str)) return;
            map.set(str,1);
            res.push(str);
            return;
        }
        for(let i=0;i<len;i++){
            if(visit[i]==1) continue;
            str+=S[i];
            visit[i]=1;
            dfs(str,visit);
            str=str.slice(0,str.length-1);
            visit[i]=0;
        }
        
    })('',visit);

    return res;
};
```
