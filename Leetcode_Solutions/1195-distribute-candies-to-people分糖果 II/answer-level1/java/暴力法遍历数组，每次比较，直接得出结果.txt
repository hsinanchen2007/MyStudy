```
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int n = 0;
        while (candies > 0) {
            ans[n % num_people] += Math.min(++n, candies);
            candies -= n;
        }
        return ans;
    }
}
```
