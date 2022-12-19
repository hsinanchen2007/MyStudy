执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
89.95%
的用户
内存消耗 :
37.3 MB
, 在所有 Java 提交中击败了
37.50%
的用户
```
class Solution {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    public List<List<Integer>> subsets(int[] nums) {
        if(nums.length==0)return res;
       // Arrays.sort(nums);
        res.add(new ArrayList<Integer>());
        int len = nums.length;
        
        get(nums, len, 0, len, new ArrayList<Integer>());
        return res;
        
    }
    private void get(int[] nums, int left, int start, int len, List<Integer> list){
        if(left==0)return;
        for(int i=start; i<len; i++){
            List<Integer> ll = new ArrayList<>(list.size()+1);
            ll.addAll(list);
            ll.add(nums[i]);
            res.add(ll);
            get(nums,left-1,i+1,len, ll);
        }
    }
}
```
