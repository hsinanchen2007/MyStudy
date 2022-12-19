### 解题思路
此处撰写解题思路
简单的遍历所有的加油站，该站满足就一直走下去，直到成功
如果中途失败怎么办？这时候我们只要在下个循环之前加入一句
if(i+cnt<gas.size() && cnt!=0)
            i=i+cnt-1;
效果翻倍，从256ms节省到了8ms，动态的选择下一个开始的加油站永远比静态的一个一个循环有用
### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++)
        {
            //看看顺时针方向行不行，再看看逆时针方向行不行
            int save=gas[i];
            int mod=gas.size();
            int j=i;
            int cnt=0;
            while(save>=cost[j] && cnt<cost.size())
            {
                save-=cost[j];
                j=(j+1)%mod;
                if(j!=i)
                save+=gas[j];
                cnt++;
            }
            if(cnt==cost.size())
            return i;
            if(i+cnt<gas.size() && cnt!=0)
            i=i+cnt-1;
           /* save=gas[i];
            cnt=0;
            k=(i-1+mod)%mod;
            while(save>=cost[k] && cnt<cost.size())
            {
                save-=cost[k];
                if(k!=i)
                save+=gas[k];
                k=(k-1+mod)%mod;
                cnt++;
            }
            if(cnt==cost.size())
            return i;*/
        }
        return -1;
    }
};
```