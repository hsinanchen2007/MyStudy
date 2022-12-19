class Solution {
    public int sumOfDigits(int[] A) {
        int min = A[0];
        for (int i = 0; i < A.length; i++) {
            if (A[i] < min) {
                min = A[i];
            }
        }
        String outs = "" + min;
        int len = outs.length();
        int out = 0;
        for (int j = 0; j < len; j++) {
            out += Integer.parseInt(outs.substring(j, j+1));
        }
        
        if (out % 2 == 0) {
            return 1;
        } else {
            return 0;
        }
    }
}