```
class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        //key值为子序列的长度，value值为一个Map,而该Map的key值为子序列第一个数字，value值为子序列
        //通过这样分开保存，可以大大减少list.contains()方法的时间；
        Map<Integer,Map<Integer,List<List<Integer>>>> map = new HashMap<>();
        add(map,new ArrayList<>(),nums,0);
        for(Integer key : map.keySet()){
            Map<Integer,List<List<Integer>>> m = map.get(key);
            for(Integer k2 : m.keySet()){
                list.addAll(m.get(k2));
            }
        }
        return list;
    }
    
    private void add(Map<Integer,Map<Integer,List<List<Integer>>>> map, List<Integer> choose, int[] nums, int index){
        if(choose.size()>1){
            if(!map.containsKey(choose.size())){
                //目前没有这种长度的子序列，直接保存
                Map<Integer,List<List<Integer>>> m = new HashMap<>();
                List<List<Integer>> l = new ArrayList<>();
                List<Integer> l2 = new ArrayList<>();;
                l2.addAll(choose);
                l.add(l2);
                m.put(choose.get(0), l);
                map.put(choose.size(), m);
            }else{
                //这种长度的子序列中，不包含以choose.get(0)为开头的子序列，直接保存
                if(!map.get(choose.size()).containsKey(choose.get(0))){
                    List<List<Integer>> l = new ArrayList<>();
                    List<Integer> l2 = new ArrayList<>();
                    l2.addAll(choose);
                    l.add(l2);
                    map.get(choose.size()).put(choose.get(0), l);
                }else{
                    //判断这种长度的子序列，以choose.get(0)为开头的子序列中，该序列是否已存在
                    if(!map.get(choose.size()).get(choose.get(0)).contains(choose)){
                        List<Integer> l2 = new ArrayList<>();
                        l2.addAll(choose);
                        map.get(choose.size()).get(choose.get(0)).add(l2);
                    }
                }
            }
        }
        if(index == nums.length){
            return;
        }
        for(int i = index; i < nums.length; i++){
            if(choose.isEmpty()){
                choose.add(nums[i]);
                add(map,choose,nums,i+1);
                choose.remove(choose.size()-1);
            }else{
                //若数字与上一位数字相同，子序列必相同，可跳过
                if(i > index && nums[i] == nums[i-1]){
                    continue;
                }
                if(nums[i] >= choose.get(choose.size()-1)){
                    choose.add(nums[i]);
                    add(map,choose,nums,i+1);
                    choose.remove(choose.size()-1);
                }
            }
            
        }
    }
}
```