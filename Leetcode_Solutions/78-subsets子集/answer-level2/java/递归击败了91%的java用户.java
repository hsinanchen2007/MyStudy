这道题我想到了两种思路。
第一种参考[77题的思路](https://leetcode-cn.com/circle/article/GV6eQ2/)
相当于在77题的基础上求k=0到n的结果
```
    private ArrayList<List<Integer>> res;
    // 求解C(n,k), 当前已经找到的组合存储在c中, 需要从start开始搜索新的元素
    private void generateCombinations(int[] nums, int n, int k, int start, List<Integer> list) {
        if (list.size() == k) {
            res.add(new ArrayList<>(list));
            return;
        }
        //减枝  i <= n-(k-list.size())+1
        for (int i = start; i < n - (k - list.size()) + 1; i++) {
            list.add(nums[i]);
            generateCombinations(nums, n, k, i + 1, list);
            list.remove(list.size() - 1);

        }
    }

    public List<List<Integer>> subsets1(int[] nums) {
        res = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return res;
        }
        List<Integer> list = new ArrayList<>();
        int len = nums.length;
        for (int i = 0; i <= len; i++) {
            generateCombinations(nums, len, i, 0, list);
        }
        return res;
    }

```
第二种方法其实相当于每个数都可以选择放或者不放。
```
private ArrayList<List<Integer>> res;

    public List<List<Integer>> subsets(int[] nums) {
        res  = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return res;
        }
        List<Integer> list = new ArrayList<>();
        res.add(new ArrayList<>());
        generate(0, nums, list);
        return res;
    }

    private void generate(int start, int[] nums, List<Integer> list) {
        //终止条件
        if (start >= nums.length) {
            return;
        }
        //选择放入次数
        list.add(nums[start]);
        res.add(new ArrayList<>(list));
        generate(start + 1, nums, list);
        //选择不放入次数
        list.remove(list.size()-1);
        generate(start + 1, nums, list);
    }
```

