1.DFS剪枝优化
```
class Solution {
    public boolean makesquare(int[] nums) {
        if (nums.length < 4) { // 优化
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        if (sum % 4 != 0) { // 优化
            return false;
        }
        Integer[] newNums = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            newNums[i] = nums[i];
        }
        Arrays.sort(newNums, new Comparator<Integer>() {
            public int compare(Integer i1, Integer i2) {
                return i2 - i1;
            }
        }); // 优化
        int[] bucket = new int[4];
        return dfs(0, newNums, bucket, sum / 4);
    }

    boolean dfs(int index, Integer[] nums, int[] bucket, int target) {
        if (index >= nums.length) {
            return bucket[0] == target && bucket[1] == target && bucket[2] == target && bucket[3] == target;
        }
        
        for (int i = 0; i < 4; i++) {
            if (bucket[i] + nums[index] > target) {
                continue;
            }
            bucket[i] += nums[index];
            if (dfs(index + 1, nums, bucket, target)) {
                return true;
            }
            bucket[i] -= nums[index];
        }
        return false;
    }
}
```
2.位运算
```
class Solution {
    public boolean makesquare(int[] nums) {
        if (nums.length < 4) { // 优化
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        if (sum % 4 != 0) { // 优化
            return false;
        }

        int target = sum / 4;
        List<Integer> ok_subset = new ArrayList<>();
        List<Integer> ok_half = new ArrayList<>();
        int all = 1 << nums.length; // 代表所有选与不选的可能
        for (int i = 0; i < all; i++) {
            int sideSum = 0;
            for (int j = 0; j < nums.length; j++) {
                if ((i & (1 << j)) != 0) {
                    sideSum += nums[j];
                }
            }
            if (sideSum == target) {
                ok_subset.add(i);
            }
        }

        for (int i = 0; i < ok_subset.size(); i++) {
            for (int j = i + 1; j < ok_subset.size(); j++) {
                if ((ok_subset.get(i) & ok_subset.get(j)) == 0) { // 未选择重复的火柴
                    ok_half.add(ok_subset.get(i) | ok_subset.get(j)); // 合并成2条边（一开始是每条边）
                }
            }
        }

        for (int i = 0; i < ok_half.size(); i++) {
            for (int j = i + 1; j <ok_half.size(); j++) {
                if ((ok_half.get(i) & ok_half.get(j)) == 0) { // 未选择重复的火柴
                    return true;
                }
            }
        }

        return false;
    }
}
```

