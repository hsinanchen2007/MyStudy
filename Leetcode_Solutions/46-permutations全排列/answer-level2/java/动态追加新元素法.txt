```
class Solution {
    /**
     * 中心思想：每追加一个元素，根据元素插入到序列中的位置不同，产生新的序列。
     * 比如：原序列是[3]，现在要追加一个新元素2，那么针对现有序列[3]，2的放置位置可以是3的前面，组成[2,3];也可以放在3的后面，组成[3,2]，依次类推。
     * 
     * res的动态变化：
     * 初始：[]
     * 第1次循环：[[3]]
     * 第2次循环：[[2, 3],[3, 2]]
     * 第3次循环：[[1, 2, 3], [2, 1, 3], [2, 3, 1], [1, 3, 2], [3, 1, 2], [3, 2, 1]]
     */
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<List<Integer>> temp;

        for (int k = nums.length - 1; k >= 0; k --) {
            if (res.size() == 0) {
                List<Integer> newItem = new ArrayList<>();
                newItem.add(nums[k]);
                res.add(newItem);
                continue;
            }

            temp = new ArrayList<>(res);
            res = new ArrayList<>();
            for (List<Integer> it : temp) {
                for (int i = 0; i < it.size() + 1; i ++) {
                    List<Integer> newItem = new ArrayList<>();
                    for (int j = 0; j < it.size() + 1; j ++) {
                        if (i == j) newItem.add(nums[k]);
                        if (j < it.size()) newItem.add(it.get(j));
                    }
                    res.add(newItem);
                }
            }
        }

        return res;
    }
}
```
