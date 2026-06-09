```java
class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int sum = 0;
        int ans = 0;
        int[] mod = new int[k];
        mod[0] = 1;
        for (int num : nums) {
            sum += num;
            int m = sum % k;
            if (m < 0) {
                m += k;
            }
            ans += mod[m]++;
        }
        return ans;
    }
}
```
