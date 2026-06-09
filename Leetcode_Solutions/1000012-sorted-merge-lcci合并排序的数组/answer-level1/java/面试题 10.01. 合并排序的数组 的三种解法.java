import java.util.*;
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        **//解法一：采用sort**
        /*for(int i=m,j=0;i<m+n;i++,j++){
            A[i] = B[j];
        }
        Arrays.sort(A);*/
        **//解法二：**双百
        /*int[] C = new int[m+n];
        int i = 0,j=0,index=0;
        while(i<m && j<n){
            if(A[i]<=B[j]){
                C[index++] = A[i++];
            }else{
                C[index++] = B[j++];
            }
        }
        if(i<m){
            for(;i<m;i++){
                C[index++] = A[i];
            }
        }
        if(j<n){
            for(;j<n;j++){
                C[index++] = B[j];
            }
        }
        for(int k=0;k<m+n;k++){
            A[k] = C[k];
        }*/
        **//解法三:采用逆向思想**双百
        while(m>0 && n>0){
            A[m+n-1] = A[m-1]>B[n-1]?A[m---1]:B[n---1];
        }
        while(n>0){
            A[n-1] = B[n-1];
            n--;
        }
    }
}