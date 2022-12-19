class Solution {
    
    public int climbStairs(int n) {
        int[] cache = new int[n + 2];
        cache[1] = 1;
        cache[2] = 2;
        for (int i = 3; i <= n; i++) {
            //对逐渐增大的i作拆分（拆分项的值从缓存可取到），并放入缓存数组，直到i到达n
            cache[i] = cache[i - 1] + cache[i - 2];
        }
        return cache[n];
    }

}