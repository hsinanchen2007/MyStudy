### 解题思路
要统计数组内数字出现次数最多了，循环数组，用哈希表记录每个数出现的次数。
再遍历哈希表，找到次数最大的那个数。

哈希表在C#里面叫字典Dictionary。
字典比哈希，更能让没有编程经验的人理解。

### 代码

```csharp
public class Solution
    {
        public int MajorityElement(int[] nums)
        {

            Dictionary<int, int> dic = new Dictionary<int, int>();

            foreach (int num in nums)
            {
                if (dic.ContainsKey(num))
                {
                    dic[num]++;
                }
                else
                {
                    dic.Add(num, 1);
                }
            }

            int maxCount = 0;
            int maxKey = 0;

            foreach (int num in dic.Keys)
            {
                if (dic[num] > maxCount)
                {
                    maxCount = dic[num];
                    maxKey = num;
                }
            }

            return maxKey;
        }
    }
```