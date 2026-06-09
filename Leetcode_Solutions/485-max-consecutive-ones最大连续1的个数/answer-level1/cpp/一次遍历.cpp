* 两个变量CurNums(当前连续1的个数)、MaxNums(最大连续1的个数)
* CurNums：每遇到一个1，CurNums加1。遇到0，则CurNums归0
* MaxNums：CurNums每次加1之后，判断CurNums是否大于MaxNums，如果是，则更新MaxNums
* 时间复杂度：O(N)
* 空间复杂度：O(1)

```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int i32CurNums = 0;
        int i32MaxNums = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (1 == nums[i])
            {
                i32CurNums++;
                
                if (i32CurNums > i32MaxNums)
                {
                    i32MaxNums = i32CurNums; 
                }
            }
            else if (0 == nums[i])
            {
                i32CurNums = 0;
            }
        }
        
        return i32MaxNums;
    }
};
```
执行结果：
执行用时:40 ms, 在所有 C++ 提交中击败了95.06%的用户
内存消耗:11.6 MB, 在所有 C++ 提交中击败了93.15%的用户
