```
public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        if(nums.Length==0) return false;
        var set=new HashSet<int>(nums);
        return set.Count==nums.Length?false:true;
    }
}
```
