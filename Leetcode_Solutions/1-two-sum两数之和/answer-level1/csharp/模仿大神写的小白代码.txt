### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        for(int i=0;i<nums.Length;i++)//只能是<不能是<=数组长度大于i和j
        for(int j=i+1;j<nums.Length;j++)//必须是i+1,不能是j=1，否则会i出现i和j相等的情况
        {
            if(nums[i]+nums[j]==target)
            {
                int [] result=new int [2];
                result [0]=i;
                result[1]=j;
                return result;//这是方法，返回值需要用于其它处，不能写Cosonle.WriteLine()执接输出
            }   
        } 
        return null;
    }
}
```