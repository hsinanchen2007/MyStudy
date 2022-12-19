class Solution {
    private int min = 0;
    
    public int minFlips(int a, int b, int c) {
        if (a == 0 && b == 0 && c== 0) {
            return min;
        }

        int i = a & 1;
        int j = b & 1;
        int k = c & 1;

        if ((i | j) != k) {
            if ((i == j) && (i == 1)) {
                min = min + 2;
            } else {
                min = min + 1;
            }
        }

        minFlips(a >> 1, b >> 1, c >> 1);

        return min;
    }
}