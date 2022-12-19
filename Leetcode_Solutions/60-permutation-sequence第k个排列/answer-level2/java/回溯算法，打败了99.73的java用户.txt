执行用时 :2 ms, 在所有 Java 提交中击败了99.73%的用户
内存消耗 :34.2 MB, 在所有 Java 提交中击败了89.52%的用户
```
public String getPermutation(int n, int k) {
        int[] help = new int[n];
        help[0] = 1;
        for (int i = 2; i <= n; i++) {
            help[i - 1] = i * help[i - 2];
        }
        String result = "";
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = i + 1;
        return back(result, nums, k, help);
    }

    public String back(String result, int[] nums, int k, int[] help) {
        int left = nums.length - result.length();
        if (left == 1) {
            result += nums[findJSmallest(nums, 1)];
            return result;
        }
        int j = k / help[left - 2];
        j = j + (k % help[left - 2] == 0 ? 0 : 1);
        int i = findJSmallest(nums, j);
        result += nums[i];
        nums[i] = Integer.MAX_VALUE;
        return back(result, nums, k - (j - 1) * help[left - 2], help);
    }

    public int findJSmallest(int[] nums, int j) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != Integer.MAX_VALUE) {
                count++;
            }
            if (j == count)
                return i;
        }
        return -1;
    }
```
