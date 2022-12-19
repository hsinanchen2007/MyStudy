### 解题思路
* 采用和#78题一样的解题思路
* 重点在于从第二个元素开始进行和前一个元素的重复比较

### 代码

```java
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        Input in = new Input();
        in.start = 0;
        in.paths = nums;
        Output out = new Output();
        out.selected = new ArrayDeque<>();
        out.result = result;
        backtrack(in, out);
        return result;
    }

    static class Input {
        int start;
        int[] paths;
    }

    static class Output {
        Deque<Integer> selected;
        List<List<Integer>> result;
    }

    private void backtrack(final Input in, final Output out) {
        // TODO: you have to sort paths
        out.result.add(new ArrayList<>(out.selected));
        for (int i = in.start; i < in.paths.length; i++) {
            int selectedItem = in.paths[i];
            // 和上个数字相等跳过，剪枝避免重复计算
            if (i > in.start && selectedItem == in.paths[i - 1]) {
                continue;
            }
            out.selected.addLast(selectedItem);
            in.start = i + 1;
            backtrack(in, out);
            in.start = i;
            out.selected.removeLast();
    }
}
```