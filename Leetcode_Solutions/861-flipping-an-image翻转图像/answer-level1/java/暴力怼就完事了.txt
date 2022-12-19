class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int[][] newArray = new int[A.length][A[0].length];
        for(int i = 0;i < A.length;i++){
            for(int j = 0; j< A[i].length; j++){
                newArray[i][j] = ((A[i][A[i].length- j - 1]) == 1) ? 0 : 1;
            }
        }
        return newArray;
    }
}