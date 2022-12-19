### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     List<List<Integer>> allList = new ArrayList<>();
    List<Integer> list = new ArrayList<>();
    int target = 0;

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        if(candidates == null || candidates.length==0) return allList;
        this.target = target;
        Arrays.sort(candidates);
        dfs(0,candidates,0);
        return allList;
    }

    private void dfs(int n, int[] candidates, int sum) {
        if(n > candidates.length){
            return;
        }else if(sum == target){
            allList.add(new ArrayList<>(list));
        }else {
            for (int i = n; i < candidates.length; i++) {
                //这个地方很关键
                if(i > n && candidates[i] == candidates[i-1]){
                    continue;
                }
                sum += candidates[i];
                list.add(candidates[i]);
                if(sum <= target){
                    dfs(i+1,candidates,sum);
                }
                sum -= candidates[i];
                list.remove(list.size()-1);
            }
        }
    }
}
```