### 解题思路
C# 二分查找

### 代码

```csharp
//二分查找法，根据求每一个屋子的离加热器的最近的位置,然后取最大值
        public int FindRadius(int[] houses, int[] heaters)
        {
            int result = int.MinValue;
            Array.Sort(houses);
            Array.Sort(heaters);

            foreach (var item in houses)
            {
                int left = 0;
                int right = heaters.Length - 1;
                int index = -1;
                //二分查找获取大于等于目标的最小值
                while (left <= right)
                {
                    int mid = left + (right - left) / 2;
                    if (heaters[mid] >= item)
                    {
                        if (mid  == 0 || heaters[mid - 1] < item)
                        {
                            index = mid;
                            break;
                        }
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }

                //index为-1表示所有加热器的位置都小于目标值
                if (index != -1)
                {
                    //index - 1 == -1，表示所有加热器位置都大于等于目标值
                    if (index - 1 == -1)
                    {
                        result = Math.Max(result, heaters[index] - item);
                    }
                    else
                    {
                        result = Math.Max(result, Math.Min(item - heaters[index - 1], heaters[index] - item));
                    }
                }
                else
                {
                    result = Math.Max(result, item - heaters.Last());
                }
            }

            return result;
        }
```