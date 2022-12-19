class Solution {
    public int stoneGameII(int[] piles) {
        int[][] dp=new int[piles.length][piles.length];
        int diff= recursive(dp,piles,0,1,true);
        int sum=Arrays.stream(piles).sum();
        System.out.println("diff"+diff+",sum"+sum);
        return (diff+sum)>>1;
    }
    public int recursive(int[][] dp,int[] piles,int start,int M,boolean isAlex){
        if(start>=piles.length){
            return 0;
        }
                int currentM=(M<<1);
        if(start+currentM>=piles.length){
            int result=sumInRange(piles,start,piles.length-1);
            dp[start][M]=isAlex?result:-result;
            return isAlex?result:-result;
        }
        if(dp[start][M]!=0){
            return dp[start][M];
        }
        int result=isAlex?Integer.MIN_VALUE:Integer.MAX_VALUE;
        for(int i=1;i<=currentM;i++){
            int nextM=Math.max(i,M);
            if(isAlex){
                int current=recursive(dp,piles,start+i,nextM,false)+sumInRange(piles,start,start+i-1);
                result=Math.max(result,current);
            }else{
                int current=recursive(dp,piles,start+i,nextM,true)-sumInRange(piles,start,start+i-1);
                result=Math.min(result,current);
            }
        }
        dp[start][M]=result;
        return result;
    }
    public int sumInRange(int[] piles,int i,int j){
        int sum=0;
        for(int k=i;k<=j&&k<piles.length;k++){
            sum+=piles[k];
        }
        return sum;
    }
}