### 解题思路
此处撰写解题思路

### 代码

```java
    class Solution {
        private List<List<Integer>> ans = new ArrayList<>();
        public List<List<Integer>> permute(int[] nums) {
            if (null == nums || nums.length == 0) {
                return ans;
            }
            dfs(nums,0,new ArrayList<>());
            return ans;
        }

        public void dfs(int [] nums,int level,List<Integer> list) {
            if (level == nums.length) {
                if (judge(list)) {
                    ans.add(new ArrayList<>(list));
                }
                return;
            }
            for (int i = 0; i < nums.length; i++) {
                list.add(nums[i]);
                dfs(nums,level + 1, list);
                list.remove(list.size() - 1);
            }
        }

        public boolean judge(List<Integer> list) {
            int length = list.size();
            for (int i = 0;i < length; i++) {
                for (int j = 0; j < length; j++) {
                    if (i != j && list.get(i) == list.get(j)) {
                        return false;
                    }
                }
            }
            return true;
        }
    }
```