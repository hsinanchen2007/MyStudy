### 解题思路
因为专业是地球物理学，所以没有用常规并查集算法，而是用地球物理学中的地震初至波走时计算的思想进行了计算，也算一种新的思路吧。
1.地震初至波走时计算的基本思路
    首先初始化矩阵为一个很大的值，然后根据已知初至波走时信息计算当前位置走时，并与当前位置原有值进行比较，如果计算结果小于当前已有的值，那么进行更新，否则不更新，因为地震初至波的遵循最短路径原理，初至波到时一定是从震源到当前位置最小的走时。
2.对于这道题的实现
    首先初始化一个M大小的向量，然后不断进行迭代，如果是朋友则把当前位置更新为两者中较小的，直到向量值不再发生变化，计算结束，最后把向量中不同数量的值找出来就是朋友圈的个数
3.时间复杂度O(n^3)，空间复杂度O(N)


### 代码

```csharp
public class Solution {
    public int FindCircleNum(int[][] M) {
        int N = M.Length;
        int[] circleRecord = new int[N];
        for(int i=0;i<N;i++)
            circleRecord[i]=i;
        //基于地球物理中走时计算思想的更新算法
        for(int loop=0;loop<N;loop++)
        {
            bool isChanged =false;
            for(int j=0;j<N;j++)
            {
                for(int i=0;i<N;i++)
                {
                    if(M[i][j]==1)
                    {
                        if( circleRecord[i]> circleRecord[j])
                        {
                            isChanged = true;
                        }
                        circleRecord[i]=(circleRecord[i]> circleRecord[j]?circleRecord[j]:circleRecord[i]);
                    }
                }
            }
            if(isChanged==false)
                break;
        }
        //基于地球物理中走时计算思想的更新算法
        /*
        int test = 9;
        for(int i=0;i<N;i++)
        {
            test = test*10+circleRecord[i];
        }
        return test;
        */
        //int[] count = new int[N];
        //for(int i=0;i<count.Length;i++)
        //    count[i]=0;
        //for(int i=0;i<N;i++)
        //{
        //    count[circleRecord[i]]=1;
        //}

        //找到不一样的个数
        Hashtable ht = new Hashtable();
        
        int reCount =0;
        for(int i=0;i<circleRecord.Length;i++)
        {
            if(ht.Contains(circleRecord[i])==false)
            {
                reCount++;
                ht.Add(circleRecord[i],"true");
            }  
        }
        //找到不一样的个数
        return reCount;
    }
}
```