class Solution {
    public boolean isHappy(int n) {
        int i = 0;
        int m=n;
        int sum =0;
        while(n>0) {
            n=n/10;
            i++;
        }
         int []a = new int[i];
        for(int j = 0 ; j<i ;j++) {
            a[j]=m%10;
            m=m/10;
        }
        for(int x=0 ;x<i;x++) {
            sum += (a[x])*(a[x]);
        }
        if(sum==1)return true;
        if(sum==3||sum==4)return false;
        return isHappy(sum);
    }
}