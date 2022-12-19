和39题的区别在避免重复上
如{1，1，2，4，6,7} sum=8，要保证[1，1，6]在解中,而解中只能有一个[1,7]
通过判断i>index && candidates[i] == candidates[i-1]来去重


```
class Solution {

    List<List<Integer>> ans = new ArrayList<>();
    int[] visited;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        visited = new int[candidates.length];
        List<Integer> list = new ArrayList<>();
        findList(list, 0, 0, candidates, target);
        return ans;
    }

    public void findList(List<Integer> list, int sum, int index, int[] candidates, int target) {
        if(sum == target) {
            ans.add(new ArrayList<>(list));
        }
        else if(sum < target) {
            for(int i=index; i<candidates.length; i++) {
                if(sum + candidates[i] > target)
                    return;
                if(i>index && candidates[i] == candidates[i-1])
                    continue;
                list.add(candidates[i]);
                findList(list, sum+candidates[i], i+1, candidates, target);
                list.remove(list.size()-1);
            }
        }
        else    return;
    }
}
```
