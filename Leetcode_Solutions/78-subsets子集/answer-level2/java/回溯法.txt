执行用时 :1 ms, 在所有 java 提交中击败了99.81% 的用户
内存消耗 :36.2 MB, 在所有 java 提交中击败了61.41%的用户
```
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> AL = new ArrayList();
        if(nums == null || nums.length < 1){
            return AL;
        }
        List<Integer> list = new ArrayList();
        AL.add(list);
        getResult(AL, list, nums, 0, nums.length);
        return AL;
    }
    public void getResult(List<List<Integer>> AL, List<Integer> list, int[] nums, int start, int end){
        if(start == end){
            return;
        }
        for(int i = start; i < end; i++){
            list.add(nums[i]);
            AL.add(new ArrayList(list));
            getResult(AL, list, nums, i+1, end);
            list.remove(list.size()-1);
        }
    }
}
```
