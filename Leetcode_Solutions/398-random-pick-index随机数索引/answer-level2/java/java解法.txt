执行用时 : 293 ms, 击败了24.05% 的用户.
内存消耗 : 69.5 MB, 击败了64.52% 的用户.
```
class Solution {
    Map<Integer,List<Integer>> map = new HashMap<>();
    public Solution(int[] nums) {
        for(int i = 0; i < nums.length; i++){
            if(map.containsKey(nums[i])){
                map.get(nums[i]).add(i);
            }else{
                List<Integer> list = new ArrayList<>();
                list.add(i);
                map.put(nums[i],list);
            }
        }
    }
    
    public int pick(int target) {
        List<Integer> list = map.get(target);
        int index = (int)(Math.random() * list.size());
        return list.get(index);
    }
}
```
