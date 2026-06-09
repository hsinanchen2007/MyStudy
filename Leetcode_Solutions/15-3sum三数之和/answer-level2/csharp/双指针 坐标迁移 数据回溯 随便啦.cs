### 解题思路

假设我有一个值（x,y,z） x代表一条直线的起点 y代表一条直线的终点 这时候z 可以在x~y之间活动 扫描符合条件的数据

如下


### 代码

```csharp
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
            Array.Sort(nums);//将杂乱数据进行排序 [-1, 0, 1, 2, -1, -4]->[-4,-1,-1,0,1,2]
            IList<IList<int>> all = new List<IList<int>>();
    
            int len = nums.Length;//数组界限
            int x = 0, y, z;//y 初始为终点 长度-1 或者可以以x为终点 0 对应的另一个点就会向终点靠近 而终点每次都会重置 
            List<int> li;
            for (; x < len-1; x++)
            {
                if (nums[x] > 0)//我以x为起点后 x下标对应的值如果大于0 那么 z=x+1 y=len-1 也必然大于0 结束后续
                    break;
                if (x > 0 && nums[x] == nums[x - 1])//起点如果跟前一个起点相等 那么这种情况已经处理过 因为z 和 y都会初始化
                    continue;
                z = x + 1;//初始化z
                y=len - 1;//初始化y
                while (z < y )//z扫描的范围到y结束
                {
                    int num = nums[x] + nums[y] + nums[z];//每次扫描的结果
                    if (num > 0)//num大于0 说明 y下标对应的值比x z下标的和还大 前进一格
                        while (y>z && nums[y] == nums[--y]) ;//相等再前进 y>z防止越界
                    else if (num < 0)
                        while ( y>z &&  nums[z] == nums[++z]) ;//相等再前进 y>z防止越界
                    else
                    {
                        li = new List<int>();//满足的情况会记录
                        li.Add(nums[x]);
                        li.Add(nums[z]);
                        li.Add(nums[y]);
                        all.Add(li);
                        while(y>x && nums[y]==nums[--y]);//前进 其他人好像还让x前进了一格 我感觉没必要 因为可能会影响到z值的情况 让y前进就行 这样z的扫描空间依旧会变窄 不存在死循环的情况
                    }
                }
              
            }
            return all;
    }
}
```