```
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] pointers = new int[primes.length];
        long[] nums = new long[n];
        nums[0] = 1;
        for(int i = 1; i < n ; i++){
            long minV = nums[pointers[0]] * primes[0];
            for(int j = 1 ; j < primes.length; j ++){
                minV = Math.min(nums[pointers[j]] * primes[j], minV);
            }
            for(int j = 0 ; j < primes.length; j ++){
                if(nums[pointers[j]] * primes[j] == minV){
                    pointers[j]++;
                }
            }
            nums[i] = minV;
        }
        return (int)nums[n - 1];
    }
}
```