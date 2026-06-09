    
    class Solution {
        public int minIncrementForUnique(int[] A) {
            if(A.length <= 1) {
                return 0;
            }
            Arrays.sort(A);
            //System.out.println(Arrays.toString(A));
            int count = 0;
            for(int i = 1;i < A.length;i++) {
                if(A[i] <= A[i - 1]) {
                    count += A[i - 1] - A[i] + 1;
                    A[i] = A[i - 1] + 1;
                }
            }
            return count;
        }
    }