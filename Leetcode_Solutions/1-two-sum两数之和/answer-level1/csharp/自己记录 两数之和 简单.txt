### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary <int, int> dic =new Dictionary <int,int> ();  // 定义哈希表
        for (int i =0; i<nums.Length;i++)                        // 循环数组nums
        {
            if (dic.ContainsKey(target-nums[i])) return new int[]  {dic[target-nums[i]],i};    //如果存在target则返回hash中存的value和i为解
            else if (!dic.ContainsKey(nums[i]))
            {
                dic.Add(nums[i],i);    // 如不存在与nums[i]配对的解 且 hash表中无重复key， 则向hash中插入(nums[i],i)
            }
                
                 
        }
        return new int[] {-1,-1}; //无解的情况
    }
}
                                                                                                                                                                                                                            执行用时 :
308 ms, 在所有 C# 提交中击败了72.96%的用户
内存消耗 :
31.2 MB, 在所有 C# 提交中击败了5.01%的用户                                                                                                                                                                                              