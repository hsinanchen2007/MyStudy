### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
    int sum=0;
    int[] result=new int[2];
    for(int i=0;i<nums.length-1;i++)
    {
        for(int j=i+1;j<nums.length;j++)
        {
            sum=nums[i]+nums[j];
            if(sum==target)
            { result[0]=i;
              result[1]=j;  
            }

        }
    }
    return result;
    }
}
```