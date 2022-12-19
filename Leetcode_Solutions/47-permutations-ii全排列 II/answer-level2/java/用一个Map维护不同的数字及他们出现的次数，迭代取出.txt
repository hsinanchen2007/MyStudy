执行结果：
通过
显示详情
执行用时 :
24 ms
, 在所有 Java 提交中击败了
36.32%
的用户
内存消耗 :
46.3 MB
, 在所有 Java 提交中击败了
40.42%
的用户
```
class Solution {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
        
    public List<List<Integer>> permuteUnique(int[] nums) {
        int len = nums.length;
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i=0; i<nums.length; i++){
            map.put(nums[i],map.getOrDefault(nums[i],0)+1);
        }
        get(map,new ArrayList<Integer>(),null);
        return res;
    }
    
    public void get(Map<Integer,Integer> map, List<Integer> list, Integer i){
        if(i!=null)remove(map,i);
        if(map.isEmpty()){
            res.add(list);
            return;
        }
        for(Integer ii: map.keySet()){
            List<Integer> ll = new ArrayList<Integer>();
            ll.add(ii);
            ll.addAll(list);
            get(new HashMap<Integer,Integer>(map),ll,ii);
        }
    }
    public void remove(Map<Integer,Integer> map,Integer i){
        if(map.get(i)>1){
            map.put(i,map.get(i)-1);
        }else{
            map.remove(i);
        }
        
    }
}
```
