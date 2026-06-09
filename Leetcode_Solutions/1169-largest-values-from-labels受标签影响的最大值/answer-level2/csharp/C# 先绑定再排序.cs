1、将value与label绑定并按value降序排列
2、使用int[]{ values[i], labels[i] } 即可绑定value与label，无需新建类或结构体
3、从新队列头开始遍历，如果该value对应的label使用次数小于use_limit就加入结果，否则继续下一个value
4、因为题目限定了 0 <= labels[i] <= 20000，所以最好用int[20001]记录每个label被使用的次数
5、当加入结果的value数量达到num_wanted时提前跳出循环返回结果

```csharp
public int LargestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit)
{
    List<int[]> list = new List<int[]>();
    for (int i = 0; i < values.Length; i++)
    {
        list.Add(new int[] { values[i], labels[i] });
    }
    int ans = 0;
    int count = 0;
    int[][] grid = list.OrderByDescending(a => a[0]).ToArray();
    int[] usedNum = new int[20001];
    for (int i = 0; i < grid.Length; i++)
    {
        if (usedNum[grid[i][1]] < use_limit)
        {
            ans += grid[i][0];
            usedNum[grid[i][1]]++;
            count++;
            if (count == num_wanted)
            {
                break;
            }
        }
    }
    return ans;
}
```