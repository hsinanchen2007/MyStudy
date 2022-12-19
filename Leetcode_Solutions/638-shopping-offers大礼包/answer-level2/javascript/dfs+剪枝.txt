```
//很慢
var shoppingOffers = function(price, special, needs) {
    var res;
    var dfs=function(sum,arr,k){
        for(var i=0;i<arr.length;i++){
            if(arr[i]>needs[i]){
                return ;
            }
        }
        if(arr.join('')===needs.join('')){
            if(res==undefined){
                res=sum;
            }else{
                if(sum<res){
                    res=sum;
                }
            }
            return ;
        }
        for(var i=0;i<price.length;i++){
            var larr=[...arr],
                sub=needs[i]-larr[i];
            larr[i]=needs[i];
            if(sub<=0)
                continue;
            dfs(sum+price[i]*sub,larr,k);
        }
        for(var i=k;i<special.length;i++){
            var larr=[...arr],
                result=true;
            for(var ii=0;ii<special[0].length-1;ii++){
                larr[ii]+=special[i][ii];
                if(larr[ii]>needs[ii]){
                    result=false;
                    break;
                }
            }
            if(result)
            dfs(sum+special[i][special[0].length-1],larr,i);
        }
    }
    var arr=new Array(needs.length).fill(0);
    dfs(0,arr,0);
    return res;
};
```