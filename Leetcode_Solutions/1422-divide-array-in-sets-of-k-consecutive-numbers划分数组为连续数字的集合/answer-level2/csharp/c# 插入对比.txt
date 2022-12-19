### 解题思路
先对数组排序 之后依次遍历 如{1,1,2,3}中读取到1 就在list中加入 (2,1+k)中的数 表示之后预期读取到的数字。如果再读取到比list[0]小1的数字 就继续把期望数字 按顺序插入到list中
如果读到list[0] 就移除并读取下一个
时间复杂度是 排序(nlogn) +计算(n^2)有点慢。提供一个思路  。还是用hash表好
### 代码

```csharp
  public class Solution
    {


        public bool IsPossibleDivide(int[] nums, int k)
        {
            if (nums.Length % k != 0)
            {
                return false;
            }
           var t= nums.ToList();
            t.Sort();
            nums = t.ToArray();

            List<int> list = new List<int>();
          
            for (int i = 0; i < nums.Length; i++)
            {
                if (list.Count==0)
                {

                    for (int j = 1; j < k; j++)
                    {
                        list.Add(nums[i] + j);
                    }
                }
                else {
                    if (nums[i] == list[0])
                    {
                        list.RemoveAt(0);
                    }
                    else if (nums[i] == list[0] - 1)
                    {
                        for (int j = 1; j < k; j++)
                        {
                            insert(list, nums[i] + j, 0, list.Count - 1);
                        }
                    }
                    else {
                        return false;
                    }
                }
 
            }
            return true;

        }

        public void insert(List<int> list,int x, int start, int end) {
            if (list.Count == 0)
            {
                list.Add(x);
            }
            else {
                if (x > list[(start + end) / 2])
                {
                    if (start >= (end - 1)) {
                        list.Insert(end+1, x);
                        return;
                    }
                    insert(list, x, (start + end) / 2, end);
                }
                else if (x < list[(start + end) / 2])
                {
                    if (start >= (end - 1))
                    {
                        list.Insert(start, x);
                        return;
                    }
                    insert(list, x, start, (start + end) / 2);
                }
                else {
                    list.Insert((start + end) / 2, x);
                }
            }
        }
        

    }
```