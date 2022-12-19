public class Solution {
    public int[] SortArrayByParityII(int[] A) {
        int target = A.Length;
        int[] B = new int[target];

        for(int i = target-1,j = (target+1)/2,k = (target+1)/2;i>=0;i--)
        {
            if(A[i]%2 == 0)
            {
                Console.WriteLine("hahaha");
                
                B[target-2*j] = A[i];
                j--;
            }
            else
            {
                B[target-2*k+1] = A[i];
                k--;
            }
        }
        return B;
        
    }
}