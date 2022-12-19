上面很多大佬的解法，很不错，但是感觉对我说稍微有点绕，在这提供一种解题思路，适合像我一样的小白看看。
取出数组第一个数nums[0]，以及除第一个数外剩下数据的全排列结果Pn-1，将nums[0]插入到Pn-1的从i到n-1每一个位置， 就可以构造出全排列数组，
表达能力有限，可以参考代码理解。


```
public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return ans;
        }
        return partition(0, nums);
    }

    public List<List<Integer>> partition(int index, int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        if (index == nums.length-1) {
            List<Integer> list = new ArrayList<>();
            list.add(nums[index]);
            ans.add(list);
            return ans;
        }

        int num = nums[index];
        List<List<Integer>> next = partition(index + 1, nums);
        int partLen = next.get(0).size();
        for (List<Integer> list : next) {
            for (int i=0; i<=partLen; i++) {
                ArrayList<Integer> list1 = new ArrayList<>(list);
                list1.add(i, num);
                ans.add(list1);
            }
        }
        return ans;
    }
```

