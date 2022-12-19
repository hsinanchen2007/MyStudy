```
//使用一个hash表储存不同的hash表
//不同的各个hash表储存相关的数据（如[['a','b'],['b','c'],['ad','da']]中，'a','b','c'储存在一个hash表，'ad'','da'储存在另一个hash表）
var calcEquation = function(equations, values, queries) {
    var hashsum=new Map(),
        len=equations.length;
    hashsum.set('hash1',new Map());
    var hash=hashsum.get('hash1');
    hash.set(equations[0][1],1);
    hash.set(equations[0][0],values[0]);
    values.shift();
    equations.shift();
    var k=2;
    while(equations.length!==0){
        var len=equations.length;
        for(var i=0;i<equations.length;i++){
            if(hash.has(equations[i][0])){
                if(hash.has(equations[i][1])!==true){
                    hash.set(equations[i][1],hash.get(equations[i][0])/values[i]);
                }
                equations.splice(i,1);
                values.splice(i,1);
                i-=1;
            }else{
                if(hash.has(equations[i][1])){
                hash.set(equations[i][0],hash.get(equations[i][1])*values[i]);
                equations.splice(i,1);
                values.splice(i,1);
                i-=1;
                }   
            }
        }
        if(len==equations.length){
            hashsum.set('hash'+k,new Map());
            hash=hashsum.get('hash'+k);
            hash.set(equations[0][1],1);
            hash.set(equations[0][0],values[0]);
            equations.shift();
            values.shift();
            k+=1;
        }
    }
    var res=[];
    for(var i=0;i<queries.length;i++){
        for(var ii=1;ii<k;ii++){
            if(hashsum.get('hash'+ii).has(queries[i][0])&&hashsum.get('hash'+ii).has(queries[i][1])){
                res.push(hashsum.get('hash'+ii).get(queries[i][0])/hashsum.get('hash'+ii).get(queries[i][1]));
                break;
            }
        }
        if(ii==k)
            res.push(-1.0);
    }
    return res;
};
```