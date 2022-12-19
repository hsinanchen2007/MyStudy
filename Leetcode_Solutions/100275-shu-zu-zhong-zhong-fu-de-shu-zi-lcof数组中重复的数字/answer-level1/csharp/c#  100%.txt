so eazy

```
public class Solution {
    public int FindRepeatNumber(int[] nums) {
            int result = 0;
            HashSet<int> set = new HashSet<int>();
            foreach (var item in nums)
            {
                if (set.Contains(item))
                {
                    result = item;
                }
                else
                {
                    set.Add(item);
                }
            }
            return result;
    }
}
```
