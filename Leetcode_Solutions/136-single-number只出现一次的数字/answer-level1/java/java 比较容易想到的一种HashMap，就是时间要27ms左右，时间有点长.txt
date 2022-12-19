使用HashMap极好,先遍历一般，目的是添加，数组元素为key,出现次数为value

```
class Solution {
    public int singleNumber(int[] nums) {
        //使用HashMap极好,先遍历一般，目的是添加，数组元素为key,出现次数为value
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            if(map.containsKey(nums[i]))
                map.put(nums[i], map.get(nums[i])+1);
            else
                map.put(nums[i], 1);
        }
        
        //然后再遍历一遍，查看哪个key的value值为1
        for(Integer key : map.keySet()){
            if(map.get(key) == 1) return key;
        }
        
        return 0;
        
    }
}
```