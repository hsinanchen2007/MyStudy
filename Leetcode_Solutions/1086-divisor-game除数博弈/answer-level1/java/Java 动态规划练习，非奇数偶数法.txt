写一个动态规划算法进行练习，放弃奇数偶数思想。
- 
- 求出所有3-N所有的因子，比较大小：
- 若得0（即可以给别人一个0），说明拿到该值必胜，将该值转化为1；
- 若得1（即必须给别人一个1），说明拿到该值必输，将该值转化为0；

- 补充：为了让dp[i] 的 i 与 N 对应，给不会出现的dp[0]和dp[1]一个极大值；
- 补充：判断dp[i-Divs.get(k)],dp[i] 的大小时，先给dp[i]，一个极大值，防止干扰

```
class Solution {
    public boolean divisorGame(int N) {        
        int [] dp = new int[N+1];
            
        if(N==1){return false;}
        else if(N==2){return true;}
        else if(N==3){return false;}
        else
        {
            
            dp[0] = 99999;
            dp[1] = 99999;
            dp[2] = 1;
            dp[3] = 0;
            
            for(int i = 4; i < N+1; i++)
            {
                ArrayList<Integer> Divs = allFactors(i);
                int length = Divs.size();
                dp[i] = 9999;
                
                for(int k=0; k<length; k++)
                {
                    dp[i] = Math.min(dp[i-Divs.get(k)],dp[i]);
                    if(dp[i] == 0 && k==(length-1)){dp[i] = 1;}
                    else if(dp[i] != 0 && k==(length-1)){dp[i] = 0;}
                }
            }
        }
        
        if(dp[N] == 0){return false;}
        else{return true;}
        
    }
    
    public ArrayList<Integer> allFactors(int a) {

        int upperlimit = (int)(Math.sqrt(a));
        
        ArrayList<Integer> factors = new ArrayList<Integer>();
        for(int i=1;i <= upperlimit; i+= 1)
        {
            if(a%i == 0){
                factors.add(i);
                if(i != a/i)
                {
                    factors.add(a/i);
                }
            }
        }
        
        Collections.sort(factors);
        return factors;
    }
    
}
```
