### 解题思路
新人接触没多久，只想到了这种写法，看了一下评论里的大佬们写的，我都脸红了。。。
这边就献丑了。
循环数组，拿本体作为比对条件，由于比对会出现自己，传入索引，自己跳出，计算对比成功结束循环，
这边还写了一个排序，因为这边对比出来的索引顺序是混乱的。
### 代码

```csharp
public class Solution {
    
    public int[] TwoSum(int[] nums, int target) {
        int[] aaa = new int[] { };
           
            for (int i = 0; i < nums.Length; i++)
            {
                aaa = aa(nums[i], i, nums, target);
                if (isok)
                {
                   return BubblingOne(aaa);
                }
                    
            }
            return BubblingOne(aaa);
    }
    bool isok = false;
    public int[] aa(int num, int index, int[] arry, int target)
        {
            for (int i = 0; i < arry.Length; i++)
            {
                if (index == i)
                {
                    continue;
                }
                if ((num + arry[i]) == target)
                {
                    isok = true;
                    return new int[] { index, i };
                }
            }
            return new int[] { };
        }

        public int[] BubblingOne(int[] nums)
        {
            List<int> list = new List<int>();
            
            int temp; 
            for (int i = 0; i < nums.Length - 1; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (nums[j] < nums[i])
                    {
                        temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                    }
                }
            }
            foreach (int c in nums) 
            {
                list.Add(c);
            }
            return list.ToArray();
        }
}
```