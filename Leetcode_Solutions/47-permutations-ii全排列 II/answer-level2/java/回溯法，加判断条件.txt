### 解题思路
回溯法可以找出全部的排列，但是因为有重复的元素，所以在全排列过程中加判断条件。
首先对数组排序。
设置标志位记录当前与元素是否访问过。
当前元素没有访问过，则可能进入全排列下一步。此时需要判断当前元素是否与上一个元素重复，且上一个元素没有访问过。当元素重复且上个相同元素没访问过时，说明此时是排列组合是重复的。当前元素虽然与上一个元素重复，但是上一个元素访问过，则肯定不会出现重复排列。思想即是保持重复元素的前后顺序不变，则不会出现重复了。

### 代码

```java
import java.util.*;
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums.length == 0)
            return res;
        boolean[] flag = new boolean[nums.length];
        ArrayList<Integer> path = new ArrayList<>();
        Arrays.sort(nums);
        find(nums, res, path, flag);
        return res;
    }
    public void find(int[] nums, List<List<Integer>> res, ArrayList<Integer> path, boolean[] flag)
    {
        if(path.size()==nums.length)
        {
            res.add(new ArrayList<>(path));
            return;
        }
        for(int i = 0; i<nums.length; i++)
        {
            if(!flag[i])
            {
                if(i-1>=0 && !flag[i-1] && nums[i]==nums[i-1])
                    continue;
                flag[i] = true;
                path.add(nums[i]);
                find(nums, res, path, flag);
                flag[i] = false;
                path.remove(path.size()-1);
            }
        }
    }
}
```