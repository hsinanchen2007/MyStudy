class Solution {
    public int[] smallestK(int[] arr, int k) {
        	        Arrays.sort(arr);
	         int[] ans = Arrays.copyOf(arr, k);
	         return ans;
    }
}