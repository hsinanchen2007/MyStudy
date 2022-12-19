class Solution {
    public boolean isMonotonic(int[] A) {
        int cum=0;
        for(int i=0;i<A.length-1;i++){
            if(A[i]<A[i+1]||A[i]==A[i+1]){
                cum++;
            }
        }
        if(cum==A.length-1){
            return true;
        }
        cum=0;
        for(int i=0;i<A.length-1;i++){
            if(A[i]>A[i+1]||A[i]==A[i+1]){
                cum++;
            } 
        }
        if(cum==A.length-1){
            return true;
        }
        return false;
    }
}