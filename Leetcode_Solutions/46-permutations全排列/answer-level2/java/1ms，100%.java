 * 1. 序列问题。和之前的下一个序列比较相似。原来想直接使用下一个序列的方式。但是觉得比较慢。要三层循环。用递归，使用一个set装着所有的剩余的数字，感觉操作
 * 也麻烦，而且速度也不快。所以采用数组标记。复杂度为排列组合，o(n！);
 * 2. 速度上：1ms，100%；内存：36.4MB，94.39%
```
public List<List<Integer>> permute(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        boolean[] flag = new boolean[nums.length];

        for (int i = 0; i < nums.length; i++) {
            flag[i] = true;
        }

        allPermute(nums, flag, result, new ArrayList());
        return result;

    }

    public void allPermute(int[] nums, boolean[] flag, List<List<Integer>> result, List<Integer> nowList) {
        if (nowList.size() == nums.length) {
            result.add(new ArrayList(nowList));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (flag[i]) {
                nowList.add(nums[i]);
                flag[i] = false;

                allPermute(nums, flag, result, nowList);

                flag[i] = true;
                nowList.remove(nowList.size() - 1);
            }
        }
    }
```

