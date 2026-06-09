class Solution {
    public boolean isPowerOfThree(int n) {
        if(n==1) return true;
        if( n%10!=3 &&  n%10!=9   &&   n%10!=7 &&  n%10!=1) return false;
        long i=1;
        while(i<n){
            i=i*9;
        }
        if(i==n || i/3 == n) return true;
        return false;
    }
}