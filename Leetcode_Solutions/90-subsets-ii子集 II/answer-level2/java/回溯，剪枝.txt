执行结果：
通过
显示详情
执行用时 :
3 ms
, 在所有 Java 提交中击败了
88.32%
的用户
内存消耗 :
37.4 MB
, 在所有 Java 提交中击败了
82.06%
的用户
```
class Solution {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    Integer min = Integer.MIN_VALUE;
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        int len = nums.length;
        if(len==0)return null;
        Arrays.sort(nums);
        
        List<Integer> list = new ArrayList<>();
        get(nums,0,list);
        return res;
    }
    
    private void get(int[] nums,int i, List<Integer> list){
        if(i==nums.length){
            List<Integer> ll = new ArrayList<>(list.size());
            for(Integer cc:list){
                if(!cc.equals(min)){
                    ll.add(cc);
                }
            }
            res.add(ll);
            return;
        }
         if(i==0||nums[i]!=nums[i-1]){
             list.add(min);
            get(nums,i+1,list);
             list.remove(list.size()-1);
             list.add(nums[i]);
            get(nums,i+1,list);
            list.remove(Integer.valueOf(nums[i]));
         }else{
              list.add(min);
            get(nums,i+1,list);
              list.remove(list.size()-1);
             if(!list.isEmpty()&&!list.get(list.size()-1).equals(min)){
                list.add(nums[i]);
                get(nums,i+1,list);
                list.remove(Integer.valueOf(nums[i]));
             }
         }
    }
}
```
