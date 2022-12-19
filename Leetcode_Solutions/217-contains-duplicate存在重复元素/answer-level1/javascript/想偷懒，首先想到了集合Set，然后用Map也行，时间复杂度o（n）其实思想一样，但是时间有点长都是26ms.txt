使用集合，没有就添加，有的话就说明之前添加过了，重复返回true
```
class Solution {
    public boolean containsDuplicate(int[] nums) {
        //使用集合，没有就添加，有的话就说明之前添加过了，重复返回true
        HashSet<Integer> set = new HashSet<Integer>();
        for(int i = 0; i < nums.length; i++){
            if(set.contains(nums[i]))
                return true;
            else
                set.add(nums[i]);
        }
        return false;
    }
}
```

使用HashMap，不存在就添加，存在就说明重复了，时间复杂度o(n)。
但是时间居然要26ms有点长。
```
class Solution {
    public boolean containsDuplicate(int[] nums) {
        //一看使用HashMap极好，一遍就行
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            if(map.containsKey(nums[i]))
                return true;
            else
                map.put(nums[i], 1);
        }
        return false;
    }
}
```