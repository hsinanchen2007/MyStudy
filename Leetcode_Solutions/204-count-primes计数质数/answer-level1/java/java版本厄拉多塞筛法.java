class Solution {

    public int countPrimes(int n) {
         boolean []flagArray = new boolean[n];
         for (int i=2; i<n; i++){
        	 flagArray[i] = true;
         }
         
         for (int i=2; i<n; i++){
        	 if (flagArray[i]){
        		 for (int k=2; k*i<n; k++){
        			 flagArray[k*i] = false;
        		 }
        	 }
         }
         
         int result = 0;
         for (int i=2; i<n; i++){
        	 if (flagArray[i]){
        		 result++;
        	 }
         }
         
         return result;
    }
}