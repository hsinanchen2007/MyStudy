```
    List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> subsets(int[] nums) {
        ans.add(new ArrayList<>());
        int l = 1, len = nums.length;

        while (l <= len) {
            for (int i = 0; i < len; i++) {
                ArrayList<Integer> list = new ArrayList<>();
                list.add(nums[i]);
                subsets(nums, l, i + 1, list);
            }
            l++;
        }
        return ans;
    }

    private void subsets(int[] nums, int len, int ind, List<Integer> path) {
        if (path.size() == len){
            ans.add(new ArrayList<>(path));
            return;
        }
        for (int i = ind; i < nums.length; i++) {
            path.add(nums[i]);
            subsets(nums, len, i + 1, path);
            path.remove(path.size() - 1);
        }
    }
```
