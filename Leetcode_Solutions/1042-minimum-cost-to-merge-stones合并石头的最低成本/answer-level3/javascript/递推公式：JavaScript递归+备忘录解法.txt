### 思路:
对于给定大小的 `stones` 我们最后一步肯定是将 `K` 堆 `stone` 合并为 `1` 堆，因此我们首先需要将 `N` 堆 `stone` 合并为 `K` 堆首先需要将 `N` 堆 `stone` 转换为 `K` 堆。可以用以下关系简单表示：  
* `N堆`=> `K堆` => `1堆`    
设将所有 `N` 堆 `stone` 转换为 `1` 堆所需要的步骤为 `a` 步，则必须满足的条件为：  
`N-a*K+a=1`   
将其转换一下：  
* `N-a*K+a=1` <=> `N-a(K-1)=1` <=> `N-1=a(K-1)` => `(N-1)%(K-1)=0`   
因此要能够转换必须满足的条件为：`(N-1)%(K-1)=0`

要求 `N` 堆转换为 `1` 堆所需的成本为：  
1. `K`堆转换为 `1` 堆所需的成本  
因为 `K` 堆能直接合并成为一堆，因此这个很好求了，直接将对应的 `stones` 累加即可，对应公式为 `sum(stones)`
2. `N` 堆转换为 `K` 堆所需的成本  
   1. 当`N<K`时，`N` 堆无法转换成为 `K` 堆    
   2. 当`N=K`时，`N` 堆转换为`K`堆的成本为：`0`
   3. 当`N>K`时，咋一看不好求，但是我们可以转换为子问题来求解

**求`N>K`时，`N` 堆 `stone` 合并为 `K` 堆所需要的成本**  
我们将 N 堆由 `m` 位置分为两个部分：
1. `[start,m]`部分   ①  
    我们将此部份再分为 `K-1` 堆
2. `[m+1,end]`部分  ②  
    我们将此部份分为 `1` 堆  

因此此时可以转换为子问题求解了：  
1. 当 `k>1` 时  
`f(start,end,k)=min(f(start,m,k-1)+f(m+1,end,1))`
2. 当 `k==1` 时  
`f(start,end,1)=f(start,end,K) + sum(start,end)`
### 代码: 
```javascript [-Java]
var mergeStones = function(stones, K) { 
    if((stones.length-1)%(K-1)!==0)return -1;
    if(stones.length===1)return 0;
    let sumArr = [];
    for(let i=0,sum=0;i<stones.length;i++){
        sum=sumArr[i]=sum+stones[i];
    }
    let hash={};
    return f(0,stones.length-1,1);
    
    function sum(start,end){
        let res = sumArr[end]-sumArr[start]+stones[start]
        // console.log(res,start,end)
        return res;
    }
    
    //将[i,j]的stones转换为k堆所需要的最低成本
    function f(start,end,k){
        let key = start+":"+end+":"+k;
        if(hash[key]!=undefined)return hash[key];
        if(k===1){
            let part1 = f(start,end,K);
            let part2 = sum(start,end);
            return hash[key]=part1+part2;
        }
        let result = Infinity;
        for(let m=start+k-2;m<end;m++){
            let part1 = (m-start+1==k-1 || start==m)?0:f(start,m,k-1);
            let part2 = m+1===end?0:f(m+1,end,1);
            result=Math.min(part1+part2,result);
        }
        return hash[key]=result;
    }
};
```