### 解题思路

##### 1. 题目概述：相对名词

##### 2. 思路：
   - 特征：给定集合数据不重复;最终的结果是自大向小排序的名词;前 3 名的输出要特殊处理;
   - 方案：将给定集合转换为带索引位置信息的集合;对新集合按照成绩逆序排列;依次公布名词;
   - 结果：存储公布名词的集合;

##### 3. 知识点：数组

##### 4. 复杂度分析: 
   - 时间复杂度：O(nlogn)
   - 空间复杂度：O(n)


### 代码

```csharp []
public class Solution {
        public string[] FindRelativeRanks(int[] nums)
        {
            var constrOne = "Gold Medal";
            var constrTwo = "Silver Medal";
            var constrThree = "Bronze Medal";
            var forReturn = new string[nums.Length];

            var listTemp = new List<ListItem>(nums.Length);
            for (var i = 0; i < nums.Length; i++)
                listTemp.Add(new ListItem(i, nums[i]));

            var orderList = listTemp.OrderByDescending(i => i.Value).ToArray();
            for (var i = 0; i < nums.Length; i++)
            {
                var curStr = "";
                switch (i + 1)
                {
                    case 1:
                        curStr = constrOne;
                        break;

                    case 2:
                        curStr = constrTwo;
                        break;

                    case 3:
                        curStr = constrThree;
                        break;

                    default:
                        curStr = $"{i + 1}";
                        break;
                }

                forReturn[orderList[i].Index] = curStr;
            }

            return forReturn;
        }

        class ListItem
        {
            public ListItem(int i, int v)
            {
                Index = i;
                Value = v;
            }

            public int Index { get; set; }

            public int Value { get; set; }
        }
}
```