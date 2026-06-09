// 其他题解都只有代码什么👻题解不应该都带上详细的解题思路么？

// 这是一个博弈问题：  
// ## 若当前为老鼠走：
// 分析老鼠的所有可走的点的情况，假如老鼠当前在`O`点，有`A、B、C、D`四点可走： 
// 1. 其中有一个点，假如是`A`，能顺利达到目标洞口，那么聪明的老鼠一定知道沿着A点走，那么可以知道当前点也能到达目标洞口
// 2. 若`A、B、C、D`都能无法达到目标洞口，这里又需要分为两种情况来看了： 
//     1. `A、B、C、D`无论走哪点都会被猫捉到，那么可以知道当前点`O`也一定会被猫捉到
//     2. `A、B、C、D`中存在一些点不会被猫捉到，也不能达到入口的，聪明的老鼠肯定知道优先从不被猫捉到的点行走了，那么可以知道当前点`O`也无法的状态就是`0`了，即不能到洞口，也不不会被猫捉住。

// 依次判断老鼠每个下个点的状态：
// 1. 若存在一个点能进洞，那么一定是老鼠赢，返回`1`
// 2. 不存在能进洞的点  
//     1. 若每一个点都将被猫捉住，那么一定是猫赢，返回`2`  
//     2. 若存在一个点，即不被猫抓住，也无法进洞那么平局，返回`0`  

// ## 若当前为猫走：
// 分析猫的所有可走的点的情况，假如猫当前在`O`点，有`A、B、C、D`四点可走：
// 1. 其中有一个点，假如是`A`，能抓到老鼠，那么聪明的猫一定知道沿着`A`点走，那么可以知道当前点也一定能抓到老鼠了。
// 2. 若`A、B、C、D`都无法抓到老鼠，那么又需要分为两种情况来讨论了：
//     1. `A、B、C、D`四个点都被老鼠逃回洞里了，那么猫无论如何也无法抓住猫，肯定是老鼠赢了
//     2. `A、B、C、D`中存在一些点能让老鼠逃不会洞里，那么聪明的猫一定走这些点，不让老鼠逃回洞里，因此猫当前点`O`的状态为既抓不住老鼠，也不会让老鼠逃到洞里面。

// 依次判断猫每个下个点的状态：
// 1. 若存在一个点都能抓到老鼠，那么一定是猫赢，返回`2`  
// 2. 不存能抓到老鼠的点  
//     1. 若每一个点都让老鼠逃回洞中了，那么一定是老鼠赢，返回`1`  
//     2. 若存在一个点既抓不住老鼠，也能阻止老鼠进洞，那么平局，返回`0`  

// 那么怎么确定那个平局的点呢？  
// 我们知道，老鼠走完整个`graph`至少需要`graph.length`步，因此老鼠到洞里的最长步数为`graph.length`步，如果这么多步数还到不了洞里，那么基本上永远也到不了洞了~，同样的道理，如果猫没能在`graph.length`步捉到老鼠那么永远也抓不到老鼠了。因此确定平局的那个点即双方都走过了`graph.length`步的那个点，即总共`2*graph.length`步的点。

// ```javascript
var catMouseGame = function(graph) {
    let N = graph.length;
    let dp = new Array(N*2).fill(0)
             .map(_=>new Array(N).fill(0)
             .map(_=>new Array(N).fill("#")));
    return tools(0,1,2);
    
    function tools(t,m,c){
        
        if(t>=2*N)return 0;                     
        if(dp[t][m][c]!="#")return dp[t][m][c];
        if(m===0) return dp[t][m][c]=1;
        if(m===c) return dp[t][m][c]=2;
        if(t%2===0){                                //老鼠走~
            let nextM = graph[m];       
            let resultSet = new Set();
            for(let nm of nextM){
                let nextAns = tools(t+1,nm,c);
                if(nextAns===1)return dp[t][m][c]=1;
                resultSet.add(nextAns);
            }
            return resultSet.size===1?(dp[t][m][c]=Array.from(resultSet)[0]):(dp[t][m][c]=0)
        }else{                                      //猫走
            let nextC = graph[c];
            let resultSet = new Set();
            for(let nc of nextC){
                if(nc===0)continue;                 //猫不能走0位置
                let nextAns = tools(t+1,m,nc);
                if(nextAns===2)return dp[t][m][c]=2;
                resultSet.add(nextAns);
            }
            return resultSet.size===1?(dp[t][m][c]=Array.from(resultSet)[0]):(dp[t][m][c]=0)
        }
    }
};
// ```