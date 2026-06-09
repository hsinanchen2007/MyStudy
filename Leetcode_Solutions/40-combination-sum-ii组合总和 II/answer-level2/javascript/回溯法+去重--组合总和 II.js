```javascript
    /**
     * 对上一期组合总和代码稍加修改即可
     * @param candidates
     * @param target
     */
    const combinationSum2 = (candidates, target)=>{
        let res=[],res0=[];
        candidates.sort();
        const dfs=(k,idx,tgt)=>{
            if(tgt===0){
                // console.info(JSON.stringify(res0.slice(0,k)));
                res.push(JSON.stringify(res0.slice(0,k)));
            }else{
                for (let i=idx;i<candidates.length;i++){
                    if(tgt-candidates[i]>=0){
                        res0[k]=candidates[i];
                        dfs(k+1,i+1,tgt-candidates[i]);
                    }
                }
            }
        };
        dfs(0,0,target);
        return [...new Set(res)].map(item=>JSON.parse(item));
    };
```
