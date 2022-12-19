### 解题思路
此处撰写解题思路
看了大佬的思路后，使用了Hash表，将时间复杂度从O(n^2)降到了O(n)，结果还是被吊打。
### 代码

```csharp
public class Solution {
        public int[] TwoSum(int[] nums, int target)
        {
            //定义大小为2的sumNum数组用于存储返回值
            int[] sumNum = new int[2];
            System.Collections.Hashtable ht = new System.Collections.Hashtable();
            //外循环：从第一个数开始
            for (int i = 0; i < nums.Length; i++)
            {
                //如果ht包含Key为：目标-当前下标的值 --[当前下标,通过结果找到对应的ht中的键值对的值]--就是需要查找的值
                //第一次循环因为ht为空直接Add
                if (ht.ContainsKey(nums[i]))
                {
                    sumNum[0] = int.Parse(ht[nums[i]].ToString());
                    sumNum[1] = i;
                    return sumNum;
                }
                //每次添加的值为<目标-当前下标的值,当前下标
                if (!ht.ContainsKey(target - nums[i]))
                {
                    ht.Add(target - nums[i], i);
                }
            }
            return sumNum;
        }
}
```