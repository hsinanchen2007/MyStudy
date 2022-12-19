class Solution {
    public int countSubstrings(String s) {
        boolean[][] dp=new boolean[s.length()][s.length()];
        int account=0;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<=i;j++){
                if(s.charAt(i)==s.charAt(j)){
                    if(i-j<3){
                        dp[j][i]=true;
                    }else{
                        dp[j][i]=dp[j+1][i-1];
                    }   
                }
                if(dp[j][i]){
                    account++;
                }
            }
        }
        return account;
    }