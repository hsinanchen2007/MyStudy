### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double[] twoSum(int n) {
        //骰子的次数
        int g_Value = 6;
        //结果概率矩阵
        double[] ratioArr = new double [n*g_Value-n+1];
        if(n < 1) return ratioArr;
        //用于计算发生次数的矩阵
        int[][] TimesArr = new int[2][n*g_Value + 1];
        //初始化
        for(int i = 1;i <= g_Value;i++){
            TimesArr[0][i] = 1;
        }
        //用于切换行的标志
        int flag = 0;
        //从第二个骰子开始计算
        for(int k = 2;k <= n;k++){
            //投第k个骰子，数值不可能小于k
            for(int i = 1;i < k;i++){
                TimesArr[1-flag][i] = 0;
            }
            //sum等于本次的次数加上先前的次数
            for(int sum = k;sum <= g_Value * k;sum ++){
                //格子初始化
                TimesArr[1-flag][sum] = 0;
                //当前投出骰子的点数1~6
                for(int cur = 1;cur <= g_Value && cur <= sum;cur++){
                    TimesArr[1-flag][sum] += TimesArr[flag][sum-cur];
                }
            }
            flag = 1 - flag;
        }
        //计算概率
        double Total = Math.pow(g_Value,n);
        for(int i = 0;i < ratioArr.length;i++){
            ratioArr[i] = TimesArr[flag][i+n] / Total;
        }
        return ratioArr;
    }
}
```