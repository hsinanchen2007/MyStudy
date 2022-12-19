class Solution {
    public int getSum(int a, int b) {
        while(b!=0){
            int skr=(a^b);
            int skrskr=(a&b)<<1;
                a=skr;
            b=skrskr;
        }
        return a;
    }
}
//x要懂^和&的意思，然后总结规律