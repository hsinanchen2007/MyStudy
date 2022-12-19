```
public class Solution {
    public int MissingNumber(int[] nums) {
          if (nums[0] == 0 && nums.Length == 1)
            {
                return 1;
            } 
            int res = -1;
            List<int> list = nums.ToList();
            list.Sort();
            int t = 0;
            bool b = true;
            for (int i = 0; i < list.Count; i++)
            {
                if (t != list[i])
                { 
                    res = t;
                    b = false;
                }
                else
                {
                    t++;
                }
            }
            if (b==true)
            {
                res = t;
            }
            return res;
    }
}
```
