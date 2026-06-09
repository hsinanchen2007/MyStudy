![image.png](https://pic.leetcode-cn.com/95290a5fda2eb94ee0e4c4e965c27d2215324e7cacd5c8565f4ee7a51440c09c-image.png)

```
//subsets[i]中保存的是以nums[i](重排后)开头的子集集合
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>>[] subsets;
        List<List<Integer>> answer;
        int i;
        
        subsets = new ArrayList[nums.length+1];
        answer = new ArrayList<>();
        Arrays.sort(nums);
        subsetsHelper(nums, 0, subsets);
        for(i = 0; i < nums.length; i++){
            if(i == 0 || nums[i] != nums[i-1])
                answer.addAll(subsets[i]);
        }
        answer.addAll(subsets[nums.length]);
        return answer;
    }
    
    private void subsetsHelper(int[] nums, int start, List<List<Integer>>[] subsets){
        List<List<Integer>> subset;
        List<Integer> list;
        int i, j;
        
        if(start == nums.length){
            subset = new ArrayList<>();
            subset.add(new ArrayList<Integer>());
            subsets[start] = subset;
        }else{
            subsetsHelper(nums, start + 1, subsets);
            subset = new ArrayList<>();
            for(i = start; i < nums.length; i++){
                if(i == nums.length - 1 || nums[i+1] != nums[i]){
                    for(j = 0; j < subsets[i+1].size(); j++){
                        list = new ArrayList<>();
                        list.add(nums[start]);
                        list.addAll(subsets[i+1].get(j));
                        subset.add(list);
                    }
                }
            }
            subsets[start] = subset;
        }
    }
}
```
