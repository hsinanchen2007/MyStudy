class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        Arrays.sort(arr);
        int[] rstArr = new int[k];
        for(int i=0;i<k;i++){
            rstArr[i]=arr[i];
        }
        return rstArr;
    }
}