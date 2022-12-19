到达stones[i]时走的步数k存储在set<int>中，讨论在i位置上的所有可能往后走的情况，如果最后stones[n-1]上可到达的种类数>1，返回true
```

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        map<int,set<int>> m;  //stones的下标i和该位置上出现过的k
        m[0]={0};
        bool f;
        for(int i=0;i<n;i++) //对于每一个stones[i]
        {
            for(int k : m[i])  //所有可到达stones[i]的k的值
            {
                //k-1 k k+1   //这三个差值范围内的步数都可以走
                f=0;
                for(int j=i+1;j<n;j++)  //从i+1位置开始向后遍历
                {
                    //取max(1,k-1)是为了让处理掉走-1和走0步的情况
                    if(stones[j]-stones[i]>=max(1,k-1) && stones[j]-stones[i]<=k+1)
                    {
                        m[j].insert(stones[j]-stones[i]);
                        f=1;
                    }
                    else if(f) break;  //f为了减少循环次数
                }
            }
        }
        return m[n-1].size()>0; //说明可到达stones[n-1]位置
    }
};
```
