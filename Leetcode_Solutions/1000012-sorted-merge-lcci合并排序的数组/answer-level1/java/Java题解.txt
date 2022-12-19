class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int aLen=m-1;
        int bLen=n-1;
        int cur=m+n-1;
        while(bLen>=0){
            if(aLen>=0&&bLen>=0){
                if(A[aLen]>B[bLen]){
                    A[cur--]=A[aLen--];
                }else{
                    A[cur--]=B[bLen--];
                }
            }else if(bLen>=0){
                A[cur--]=B[bLen--];
            }
        }
    }
}