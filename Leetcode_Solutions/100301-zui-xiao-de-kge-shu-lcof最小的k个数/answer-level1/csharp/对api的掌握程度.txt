public class Solution {
    public int[] GetLeastNumbers(int[] arr, int k) {
            Array.Sort(arr);
            int[] arrb = new int[k];
            Array.Copy(arr, 0, arrb, 0, k);
            return arrb;
    }
}