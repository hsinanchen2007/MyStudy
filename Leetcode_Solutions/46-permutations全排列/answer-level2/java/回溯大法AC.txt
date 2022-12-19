### 解题思路
回溯全排列

### 代码

```java
class Solution {
    
    List<List<Integer>> result = new LinkedList<>();
    public List<List<Integer>> permute(int[] nums) {
        LinkedList<Integer> track = new LinkedList<>();
        backtrack(nums, track);
        return result;
    }

    private void backtrack(int[] candidates, LinkedList<Integer> track) {
        if (track.size() == candidates.length) {
            result.add(new LinkedList<>(track));
            return;
        }

        for (int i = 0; i< candidates.length; i++) {
            if (track.contains(candidates[i])) {
                continue;
            }

            // 选择
            track.add(candidates[i]);
            // 回溯
            backtrack(candidates, track);
            // 撤销
            track.pollLast();
        }
    }
}
```