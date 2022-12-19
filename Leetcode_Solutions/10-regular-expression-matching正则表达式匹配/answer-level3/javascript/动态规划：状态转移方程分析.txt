#### 个人解读
1. 使用动态规划方法，创建模型。
    该问题可以分析为使用 p的前j个字符 匹配 s的前i个字符。
s：待匹配字符
p: 匹配规则
dp[i][j]：状态数组，表示用p的前j个字符 匹配 s的前i个字符的结果

2. 子问题分析
     1. p[j] == s[i] 或 p[j] == '.' ---> dp[i][j] = dp[i-1][j-1];
     2. p[j] == '*' ---> 分两种情况
         - 1. p[j-1] == s[i] ---> dp[i][j] = dp[i][j-2] 或 dp[i][j-1] 或 dp[i-1][j]  
           解读：
              这里要将p和s都各自分为两部分
              将p分为：*前j-2个 和 最后2个。* 
              将s分为：*被p[j-2]匹配了的部分 和 未被匹配的部分(会被b*匹配的部分))*
              p的前j-2个字符匹配了s的一部分字符，那么剩下的2个字符(如b*)要匹配s的剩下部分字符
              这里s剩下的字符可能是 0个、1个、多个。因为可能性是这其中一个所以是'或'的关系。
           dp[i][j-2] //意思：p的最后两个(如b*)匹配到的字符是0个 
           dp[i][j-1] //意思：p的最后两个(如b*)匹配到的字符是1个   b
           dp[i-1][j] //意思：p的最后两个(如b*)匹配到的字符是多个  bbbbb
        - 2. p[j-1] != s[i] ---> dp[i][j] = dp[i][j-2]

3. 边界值分析
当s和p最终都为空的时候，结果为true
当s和s有一个不为空的时候，结果为false  -------(''与'.*'这种情况：dp[i][j]=dp[i][j-2])

4. 附上代码
    (代码中dp[0][0]为p的第一个匹配s的第一个。)
```javascript []
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */

var isMatch = function(s, p) {
    var dp = new Array(s.length);
    dp.fill('-1');//foreach会跳过空元素，所以初始化
    dp.forEach((item,index)=>{
        dp[index] = new Array(p.length);
        dp[index].fill('-1');
    })
    function ismatch(s,p,i,j){
        if(i==0 || j==0){
            if(i==j){
                return true; // '' ''
            }
            if(j!=0 && p.charAt(j-1)=='*'){
                return ismatch(s,p.slice(0,-2),i,j-2);
            }
            return false;
        }
        if(dp[i-1][j-1] != '-1'){
            return dp[i-1][j-1];
        };
        if(i==1 && j==1){
            if(p.charAt(0) == '.'){
                dp[0][0] = true;
            }else{
                dp[0][0] = s==p
            }            
            return dp[0][0];
        }                
        if(p.charAt(j-1) == '*'){ 
            if(s.charAt(i-1) == p.charAt(j-2) || p.charAt(j-2) == '.'){
                dp[i-1][j-1] = (
                    ismatch(s, p.slice(0,-1), i, j-1) ||
                    ismatch(s.slice(0,-1), p, i-1, j) ||
                    ismatch(s, p.slice(0,-2), i, j-2)
                );
            }else if(s.charAt(i-1) != p.charAt(j-2)){
                dp[i-1][j-1] = ismatch(s,p.slice(0,-2),i,j-2)
            }            
        }else if(p.charAt(j-1) == '.' || p.charAt(j-1) == s.charAt(i-1)){
            dp[i-1][j-1] = ismatch(s.slice(0,-1), p.slice(0,-1), i-1, j-1);   
        }else{
            dp[i-1][j-1] = false;
        }
        return dp[i-1][j-1];
    }    
    return ismatch(s,p,s.length,p.length);
};
```



