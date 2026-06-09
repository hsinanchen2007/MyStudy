动态规划，二维数组，通过
执行结果：
通过
显示详情
执行用时 :
133 ms
, 在所有 Java 提交中击败了
6.40%
的用户
内存消耗 :
36.7 MB
, 在所有 Java 提交中击败了
48.55%
的用户
```
class Solution {
    int max=0;
    public int maxProfit(int k, int[] prices) {
        if(k==0)return 0;
        int len = prices.length;
        if(len<=1)return 0;
        
        
        k = Math.min(k,len>>>1);
        //已经交易了几次,现在手上是否有股票
        int[][] res = new int[k+1][2];
        int x = k+1;
        for(int j=0; j<x;j++){
            res[j][1]=Integer.MIN_VALUE;
        }
        res[0][0]=0;
        res[0][1]=0-prices[0];
            
       for(int i=1; i<len; i++) {
            int y = Math.min(k,(i+1)>>>1);
            int z = (i)>>>1;
            for(int j=0; j<=y;j++){
                if(j<=z)res[j][1]=Math.max(res[j][0]-prices[i],res[j][1]);
                if(j<k&&prices[i]>prices[i-1]){
                    // res[j+1][0]=Math.max(res[j+1][0],prices[i]+res[j][1]);
                    //  if(res[j+1][0]>max)max=res[j+1][0];
                    if(res[j+1][0]<prices[i]+res[j][1]){
                        max = res[j+1][0] = prices[i]+res[j][1];
                    }
                }
            }
       }
        return max;
    }
}
```

动态规划，三维数组，执行到1000000000那组数据超时
```
class Solution {
    int max=0;
    public int maxProfit(int k, int[] prices) {
        if(k==0)return 0;
        int len = prices.length;
        if(len<=1)return 0;
        
        
        k = Math.min(k,len/2);
        System.out.println(k);
        //第几天，已经交易了几次,现在手上是否有股票
        int[][][] res = new int[len][len/2+2][2];
        for(int i=1; i<len; i++){
            int x = Math.min(k+1,(i+1)/2);
            for(int j=0; j<=x;j++){
                res[i][j][1]=Integer.MIN_VALUE;
            }
        }
        res[0][0][0]=0;
        res[0][0][1]=0-prices[0];
        
        for(int i=1; i<len; i++){
            int x = Math.min(k,(i)/2);
            
            for(int j=0; j<=x;j++){
                // if(j>0){
                    res[i][j][0]=Math.max(res[i][j][0],res[i-1][j][0]);
                // }else{
                //     res[i][j][0]=res[i-1][j][0];
                // }
                // if(i==4&&j==1){
                //     System.out.println("==411=="+res[i-1][j][0]+"====="+prices[i]+"===="+res[i-1][j][1]);
                // }
                res[i][j][1]=Math.max(res[i-1][j][0]-prices[i],res[i-1][j][1]);
               // System.out.println(i+"+"+(j)+"=+1=="+res[i][j][1]);
                res[i][j+1][0]=prices[i]+res[i-1][j][1];
               // System.out.println(i+"+"+(j+1)+"=+0=="+res[i][j+1][0]);
                // if(j<=k&&res[i][j][0]>max){
                //     max=res[i][j][0];
                // }
                
                
                // if(j+1<=k&&res[i][j+1][0]>max){
                //     max=res[i][j+1][0];
                // }
                
                
               // if(j+1==k&&res[i][j+1])
                
            }
        }
        int x = (len+1)/2;
        int ii=len-1;
        for(int j=0; j<=k;j++){
            if(res[ii][j][0]>max)max=res[ii][j][0];
        }
        return max;
        
        
    }
    
}
```



递归计算到9次时超时，
```
class Solution {
    int max=0;
    public int maxProfit(int k, int[] prices) {
        if(k==0)return 0;
        int len = prices.length;
        if(len<=1)return 0;
        calc(k,prices,0,0,false,0,0);
        return max;
    }
    private void calc(int k,int[] prices, int cur, int sum, boolean bought, int pre, int count){
        if(cur>=prices.length)return;
        if(bought){
            if(prices[cur]>pre){
                int newsum =sum+ prices[cur]-pre;
               // System.out.println("=="+newsum+"="+prices[cur]+"+"+pre);
                if(newsum>max){
                    max=newsum;
                }
                if(count+1<k){
                    calc(k,prices,cur+1,newsum,false,0,count+1);
                }
            }
            calc(k,prices,cur+1,sum,true,pre,count);
        }else{
            calc(k,prices,cur+1,sum,false,0,count);
            calc(k,prices,cur+1,sum,true,prices[cur],count);
        }
    }
}
```
