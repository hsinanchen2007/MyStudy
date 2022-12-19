### 解题思路
此处撰写解题思路
已经比较过的值就不要在后面进行比较了，也可以使用List存储已经比较过的值
### 代码

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {
            int a = 0;
            
           
            int leng = nums.Length;
            for (int i = 0; i < leng; i++)
            {
                int count = 0;
                bool flag = false;
                for (int j = 0; j < i; j++)
                {
                    if (nums[i] == nums[j])
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    continue;
                else
                {
                    for (int k=i;k<leng;k++)
                    {
                        if (nums[i] == nums[k])
                            count++;
                    }

                }

                if (count > (leng - i) / 2)
                    return nums[i];

            }
            return a;
    }
}
```