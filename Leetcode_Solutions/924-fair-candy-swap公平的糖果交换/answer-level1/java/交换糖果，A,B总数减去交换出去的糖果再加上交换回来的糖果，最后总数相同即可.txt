class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int asum=0;
        int bsum=0;
        int eqsuma=0;
        int eqsumb=0;
        for(int i=0;i<A.length;i++)
        {
            asum+=A[i];
        }
        for(int j=0;j<B.length;j++)
        {
            bsum+=B[j];
        }
        for(int i=0;i<A.length;i++)
        {
            eqsuma=asum-A[i];
            for(int j=0;j<B.length;j++)
            {
                eqsumb=bsum-B[j];
                if(eqsumb+A[i]==eqsuma+B[j])
                {
                    int[] ans=new int[]{A[i],B[j]};
                    return ans;
                }
            }
        }
        return null;
    }
}