令桶的大小gap = (max - min) / n, 显然要求的最大间距肯定大于gap（可以用反证法证明这一点，如果最后的最大间距小于等于gap的话，从min开始往后排显然排不到max）。把每个元素分配到对应的桶里，这样的话同一个桶里面的元素之间的间距就不需要考虑了。我们只需记录每个桶的最大元素和最小元素，然后依次比较当前桶的最小元素和前一个桶的最大元素之间的间距，最大值即为所求。
```
class Solution {
    public int maximumGap(int[] nums) {
        int n = nums.length;
        if (n < 2) return 0;
        int min = nums[0], max = nums[0];
        for (int num: nums) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }
        int gap = (max - min) / n;
        int[] minBucket = new int[n];
        Arrays.fill(minBucket, -1);
        int[] maxBucket = new int[n];
        Arrays.fill(maxBucket, -1);
        for (int num: nums) {
            int idx = (num- min) / (gap + 1);
            if (minBucket[idx] == -1)
                minBucket[idx] = num;
            else minBucket[idx] = Math.min(minBucket[idx], num);
            if (maxBucket[idx] == -1)
                maxBucket[idx] = num;
            else maxBucket[idx] = Math.max(maxBucket[idx], num);
        }
        int ans = 0, bound = maxBucket[0];
        for (int i=1; i<n; i++) {
            if (minBucket[i] != -1) {
                ans = Math.max(ans, minBucket[i] - bound);
                bound = maxBucket[i];
            }
        }
        return ans;
    }
}
```