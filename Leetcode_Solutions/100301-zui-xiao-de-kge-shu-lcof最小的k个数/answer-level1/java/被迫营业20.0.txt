class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
	Arrays.sort(arr);
    	return Arrays.copyOf(arr, k);
    }
}