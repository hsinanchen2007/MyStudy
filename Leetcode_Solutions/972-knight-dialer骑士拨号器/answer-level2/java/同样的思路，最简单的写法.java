```
class Solution {
    
    private static final int mod = 1000000007;

    public int knightDialer(int N) {
        long[] array = new long[10];
        Arrays.fill(array, 1);
        for(int n = 2; n <= N; n++) {
            long a1 = array[6] + array[8];
            long a2 = array[7] + array[9];
            long a3 = array[4] + array[8];
            long a4 = array[3] + array[9] + array[0];
            long a6 = array[1] + array[7] + array[0];
            long a7 = array[2] + array[6];
            long a8 = array[1] + array[3];
            long a9 = array[4] + array[2];
            long a0 = array[4] + array[6];
            array[0] = a0 % mod;
            array[1] = a1 % mod;
            array[2] = a2 % mod;
            array[3] = a3 % mod;
            array[4] = a4 % mod;
            array[5] = 0;
            array[6] = a6 % mod;
            array[7] = a7 % mod;
            array[8] = a8 % mod;
            array[9] = a9 % mod;
        }
        
        long sum = 0;
        for(long a : array) {
            sum += a;
        }
        
        return (int)(sum % mod);
    }
}
```
