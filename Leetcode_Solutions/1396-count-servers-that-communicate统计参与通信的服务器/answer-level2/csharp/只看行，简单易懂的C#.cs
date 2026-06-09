
只看行的话，一共分为三种情况记为a,b,c。

a行：和大于1，a行服务器数量为该行和。例如[1,1,0,0]服务器数量为2
b行：和等于1，b行最多存在一个服务器，如果该服务器对应的其他行相同列也有服务器，则为1，否则为0。例如[[1,0],[1,0]]两个b行都存在一个服务器，而[[1,0],[0,1]]不存在服务器。
c行：和为0，直接不用考虑，服务器数量为0。

此时总的服务器数量就是所有a行服务器的总和加上b行服务器的总和。
对abc行的分类直接通过行的和是否大于等于1进行，可以用linq直接将a,b,c行分开，或者写个行的遍历就行。


```
public class Solution
{
    public int CountServers(int[][] grid) 
    {
        int count = grid.Where(i=>i.Sum()>1).Select(i=>i.Sum()).Sum();//a行的服务器数量
        count = count + grid.Where(i => i.Sum() == 1).Select(x =>
        {
            int index = ReturnIndex(x);
            if ((int)grid.Where(j => j[index] != 0).Count() > 1) return 1;
            return 0;
        }).Sum();//加上b行的服务器数量
        return count;
    }
    public static int ReturnIndex(int[] x)//返回b行服务器所在列数
    {
        for(int i = 0;i<x.Length;i++)
        {
            if (x[i] == 1) return i;
        }
        return 0;
    }
}
```
