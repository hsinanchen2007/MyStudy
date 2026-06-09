不理解请私信联系我，具体的剪枝过程有点复杂。以及不是相关专业学生，代码不规范请见谅

一次遍历的动态规划。
看到很多人说仅仅通过n-1的状态来写状态转移不可行，这里给出一种实现，需要记录每个节点的最优值和所谓的“换头次优值”（注意不是真的次优值），以及最优时当下节点（我称为前n个房子的头）的颜色。
只有换了头颜色的次小才是有意义的（因为可以给后面更多选择。头不换后面都是一样的）
状态转移方程有点复杂，其中核心在于优化剪枝（比如很多地方隐含着头相等或者不相等），很多隐含条件都是可以考虑到然后不去比较的。
上面定义的函数可以返回三个数的最小编号和次小编号（等号成立条件保证排序的稳定性。注意返回的是编号，也就是0,1,2中的某个。）
temp用来存第二小的颜色编号（因为并不在数据结构中保存所以只用一个空间来存）
F_Min 和S_Min 分别是最小和换头次小花费。
color用来存最优的解法的头的颜色。(012表示)
其中有个神秘代码3-m-temp其实代表最大的颜色，因为m是最小，temp是次优，0+1+2=3，剩下的就是最大的编号。
```
public class Solution 
{
    //返回三个数的最小编号和次小编号（等号成立条件保证排序的稳定性
    public int Compare(int[]costs,out int next)
    {
        next = 0;
        int r = 0;
        if(costs[0]<=costs[1])
        {
            r = 0;
            next = 1;
        }
        else
        {
            r=1;
            next=0;
        }
        if(costs[2]<costs[next])
        {
            if(costs[2]<costs[r])
            {
                next = r;
                r = 2;
            }
            else
                next = 2;
        }
        return r;//next通过out返回。
    }


    public int MinCost(int[][] costs)
    {
        int l = costs.Length;
        int temp;
        if(l<1)
            return 0;

        //分别是最小和换头次小花费
        int[] F_Min = new int[l];
        int[] S_Min = new int[l];

        //用来存最优的解法的头的颜色。(012表示)
        int[] color = new int[l];

        //定义初值
        F_Min[0] = costs[0][Compare(costs[0],out temp)];
        S_Min[0] = costs[0][temp];
        color[0] = Compare(costs[0],out temp);

        //判断边界
        if(l==1)
            return F_Min[0];

        //状态转移
        for(int i = 1;i<l;i++)
        {
            int m = Compare(costs[i],out temp);
            if(m!=color[i-1])//不冲突的情况
            {
                color[i] = m;
                F_Min[i] = F_Min[i-1] + costs[i][m];
                if(color[i-1]!=temp)//剩下的次小的颜色，则一定对应换头次优
                    S_Min[i] = F_Min[i-1] + costs[i][temp];
                else//剩下的是最大的颜色，则换头次优可能以次小或者最大作为头。两者较优的为次优解。
                {
                    S_Min[i] = Math.Min(F_Min[i-1]+costs[i][3-m-temp],S_Min[i-1]+costs[i][temp]);
                }
            }
            else //对应冲突的情况
            {
                //对应最优值为前i-1个取最优，i取次优的情形
                if(F_Min[i-1]+costs[i][temp]<S_Min[i-1]+costs[i][m])//一个min函数可以求出F_Min的值，但是没法确定S_Min，所以还是要分类
                {
                    F_Min[i] = F_Min[i-1]+costs[i][temp];
                    color[i] = temp;
                    S_Min[i] = Math.Min(S_Min[i-1]+costs[i][m],F_Min[i-1]+costs[i][3-m-temp]);
                }
                //对应最优值为 前i-1个取换头次优，i取最优的情形
                else
                {
                    F_Min[i] = S_Min[i-1]+costs[i][m];
                    color[i] = m;
                    S_Min[i] = F_Min[i-1]+costs[i][temp];
                }
            }
        }
        return F_Min[l-1];
    }
}
```

