如果重复元素的次数严格大于N,则可以直接两两比较，本题的话可以每次取n=4个进行两两比较：

class Solution {
    public int repeatedNTimes(int[] A) {
        for(int i=0;i<A.length-3;i+=4){
           if(find(A,i)!=-1) return find(A,i);
        }
        return 0;
    }
    //
    public int find(int[] A, int i){
        if(A[i]==A[i+1]) return A[i];
        if(A[i]==A[i+2]) return A[i];
        if(A[i]==A[i+3]) return A[i];
        if(A[i+1]==A[i+2]) return A[i+1];
        if(A[i+1]==A[i+3]) return A[i+1];
        if(A[i+2]==A[i+3]) return A[i+2];
        return -1;
    }
}
复杂度应该是O(6*N/4)=O(N)?