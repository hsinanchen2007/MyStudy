蠢萌思路如下：
1.当步骤为alice的时候，她的下一步存在任意一个为true的可能，则最终结果为true，否则为false
2.当步骤为bob的时候，他的下一步每一种取数的结果必须为true，最终结果才为true，否则为false
请见屎一样的代码。
```
var divisorGame = function(N) {
   //Alice 步骤：  1=false   2=true  3=false    1表示alice
   //Bob   步骤：  1=true    2= false 3= true   0表示bob
    var dp = new Array(2);
    for(let i=0;i<dp.length;++i){
        let arr = new Array(N+1);
        dp[i] = arr;
    }
        //dp[][]  存储每一种情况的结果
    dp[1][1] = false;
    dp[1][2] = true;
    dp[0][1] = true;
    dp[0][2] = false;
    getRes(N,dp,1);
    return dp[1][N];
};

//flag=1  表示爱丽丝的步骤  0表示鲍步的步骤
var getRes = function(N,dp,person){
    if(dp[person][N]!=undefined) return dp[person][N];
    let nextPerson = person==1? 0 : 1;
    let temp = person==1 ? false : true;
    for(let i=1;i<N;++i){
        if(N%i==0){
            if(person==1) {
                    //当为alice先手的时候 分支有一个为true即可
                temp = temp || getRes(N-i,dp,nextPerson);
                if(temp==true) {
                    dp[person][N] = true;
                    return true;
                } 
            } else {
                    //当为bob的步骤时，必须每一个分支都为true dp[person][N]才为true，否则为false
                temp = temp && getRes(N-i,dp,nextPerson);
                if(temp==false) {
                    dp[person][N] = false;
                    return false;
                }
            }
        }
    }
    dp[person][N] = person==1? false : true;
    return dp[person][N];
}
```
