- 整体还是回溯
- 路径 `Integer[] curr` 替代了 `Stack` 或 `Deque` 或 `List<Integer>`
- 选了谁 `int occupy` 替代了 `boolean[] used`
- `int ci` 表示 `curr` 当前的 `index`
```java
public List<List<Integer>> permute(int[] nums) {
    int len = nums.length;
    if (len == 0) return Collections.emptyList();

    List<List<Integer>> res = new LinkedList<>();
    bt(nums, new Integer[len], 0, 0b0, res);
    return res;
}

private void bt(int[] nums, Integer[] curr, int ci, int occupy, List<List<Integer>> res) {
    if (occupy == (1 << nums.length) - 1) { // 每个数都选了
        res.add(new ArrayList<>(Arrays.asList(curr)));
        return;
    }

    for (int i = 0; i < nums.length; i++) {
        if (((occupy >> i) & 1) == 1) continue; // 已选中
        occupy |= 1 << i; // 勾选
        curr[ci] = nums[i];
        bt(nums, curr, ci + 1, occupy, res);
        occupy &= (~(1 << i)); // 去选
    }
}
```
