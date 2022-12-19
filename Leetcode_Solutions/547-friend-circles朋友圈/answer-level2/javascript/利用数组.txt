```
//本来准备用hash表的，发现不好合并，就使用数组。
//一个二维数组，储存每个朋友圈的同学编号，同时不断合并数组，最后得到朋友圈数量
var findCircleNum = function(M) {
    var  hash=[],
           result=true;
    for(var i=0;i<M.length;i++){
        for(var ii=0;ii<M[0].length;ii++){
            if(M[i][ii]!==1)
                continue;
            for(var k=0;k<hash.length;k++){
                if(hash[k].indexOf(i)!==-1){
                    if(hash[k].indexOf(ii)===-1){
                        hash[k].push(ii);
                    }
                        result=false;
                        break;
                }else{
                    if(hash[k].indexOf(ii)!==-1){
                        hash[k].push(i);
                        result=false;
                        break;
                    }
                }
            }
            if(result){
                if(i!==ii)
                    hash.push([i,ii]);
                else
                    hash.push([i]);
            }
            result=true;
            var ki=undefined;
            for(var kii=0;kii<hash.length;kii++){
                if(hash[kii].indexOf(i)!==-1||hash[kii].indexOf(ii)!==-1){
                    if(ki===undefined){
                        ki=kii;
                    }else{
                        hash[kii]=[...hash[kii],...hash[ki]];
                        hash.splice(ki,1);
                        kii-=1;
                    }
                }
            }
        }
    }
    return hash.length;
};
```