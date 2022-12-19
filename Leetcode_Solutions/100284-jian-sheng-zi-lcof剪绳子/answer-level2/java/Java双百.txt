class Solution {
   public int cuttingRope(int n) {
       if(n==2)return 1;
       if(n==3)return 2;
        if(n%3==1){
            return (int) (Math.pow( 3,(n/3)-1)*4);
        }else if(n%3==2){
            return (int)Math.pow(3,n/3)*2;
        }else{
            return (int)Math.pow(3,n/3);
            }
    }
}