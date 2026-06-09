主要思路和two-sum神似，注意k=0和k<0（细节决定成败。。）的情况。
有人预先进行了排序，虽然对于主体判断有一定的简化作用，但是排序依然需要O(nlog(n))，这里的时间复杂度不能漏了，所以不考虑预先排序还是首选。

```
class Solution {
    public int findPairs(int[] nums, int k) {
        // for cases of negative k
        if (k < 0) return 0;

        int count = 0;
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            // if the key already exists, count ++ for k == 0 and for the first time of counting this key
            if (map.containsKey(nums[i])) {
                if (k == 0 && map.get(nums[i]) != Integer.MAX_VALUE) count ++;
                map.put(nums[i], Integer.MAX_VALUE);
            }
            // if the key doesn't exist, put into the map and search for nums[i] +/- k
            else {
                map.put(nums[i], i);
                if (k != 0 && map.containsKey(nums[i] + k)) count ++;
                if (k != 0 && map.containsKey(nums[i] - k)) count ++;
            }
        }

        return count;
    }
}
```
