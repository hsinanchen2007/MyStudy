基本思想：
看到题目就想用动态规划，然而递推方程不好写，这能曲线救国了。
记res为动态规划数组，自然，res的计算是从后往前的。
以下讨论res[i]的递推：
1）T[i]<T[i+1] 和 T[i]==T[i+1] 时较简单，参见代码
2）T[i]>T[i+1]时，从i+1开始向后查询，直到遇到i开始的最高温或者更高温，利用该天的温度更新res[i+1]

```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        int n=T.size();
        if(n==0)
        return {};
        vector<int> res(n);
        res[n-1]=0;//最后一天肯定为0
        for(int i=n-2;i>=0;--i)
        {
            if(T[i]<T[i+1]) //第二天就是更高温度
            res[i]=1;
            else if(T[i]==T[i+1])
            {
                if(res[i+1]) //同温度，且第二天非最高温
                res[i]=res[i+1]+1;
                else  //同温度，且第二天就是最高温（i开始的最高温）
                res[i]=0;
            }
            else
            {
                int j=i+1; 
                while(res[j] && T[j]<=T[i]) //向后查询，直到最高温或者更高温
                j+=res[j];//跳跃到 j+res[j] 天
                if(T[j]>T[i]) //更高温
                res[i]=j-i;
                else  //最高温
                res[i]=0;
            }
        }
        return res;

    }
};
```
