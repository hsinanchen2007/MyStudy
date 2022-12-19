### 解题思路
题目要求我们只使用三角形行数的空间，那么三角形行数就是list的size，同时也是最后一行的列数，则我们使用动态规划，建立一个dp数组，通过不断更新来覆盖掉之前的值，最终得出到末行所有位置各所需的最短路程，然后返回其中最小的就是我们的最短路径

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int[]dp=new int[triangle.size()];
        Iterator<List<Integer>> it=triangle.iterator();//遍历器遍历
        int res=Integer.MAX_VALUE;
        while(it.hasNext())
        {
            List<Integer> tempList=it.next();
            for(int i=tempList.size()-1;i>=0;i--)//从最外边的数字开始遍历，以防前一行所记录的数字被提前覆盖掉而出现数据计算错误
            {
                if(i==0)dp[0]+=tempList.get(i);//由于只能往正下或右下走，所以第一列永远只能直线往下走
                else{
                    if(i==tempList.size()-1)//最外围的永远只有右下的走法
                    {
                        dp[i]=tempList.get(i)+dp[i-1];
                    }else{
                        dp[i]=tempList.get(i)+Math.min(dp[i],dp[i-1]);//判断最短的走法
                    }
                }
                if(tempList.size()==dp.length)res=Math.min(res,dp[i]);//最末行找最小值
            }
        }
        return res;
    }
}
```