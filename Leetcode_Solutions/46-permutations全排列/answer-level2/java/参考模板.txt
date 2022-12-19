### 解题思路
通用方法就是回溯算法。旧文「回溯算法详解」写过回溯算法的模板：
```
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

### 代码

```java
class Solution {
    List<List<Integer>> res;
    public List<List<Integer>> permute(int[] nums) {
        res = new ArrayList<>();
        ArrayList<Integer> output = new ArrayList<>();
        backtrack(nums, output);
        return res;
    }

    private void backtrack(int[] nums, ArrayList output) {
        if (output.size() == nums.length) {
            res.add(new ArrayList<>(output));
            return;
        }

        for (int i = 0; i< nums.length; i++) {
            if (output.contains(nums[i])) {
                continue;
            }
            output.add(nums[i]);
            //进入下一层决策树
            backtrack(nums, output);
            output.remove(output.size() -1);
        }
    }
}
```