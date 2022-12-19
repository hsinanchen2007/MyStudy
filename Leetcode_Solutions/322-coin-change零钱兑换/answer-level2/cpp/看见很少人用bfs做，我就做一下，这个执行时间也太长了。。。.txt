### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int res=-1;
    int flag=0;//flag=1的时候才有可行解
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int len=coins.size();
        if(amount==0)return 0;
        queue<int> qu;
        qu.push(amount);
        int dep=0;
        vector<bool> v(amount,false);
        bfs(qu,coins,v,dep);
        return flag==1?dep:-1;

    }
    void bfs(queue<int> &qu,vector<int>& coins, vector<bool> &v,int &dep)
    {
        while(!qu.empty())
        {
            dep++;
            int size=qu.size();//现在那一层的结点数
            while(size>0)
            {
                int temp=qu.front();
                qu.pop();
                for(int i=0;i<coins.size();i++)
                {
                    if(temp-coins[i]==0)
                    {
                        //碰到0，说明有至少有一种可行解了，flag=1；
                        flag=1;
                        return ;
                    }
                        
                    else if(temp-coins[i]>0)
                    {
                        if(v[temp-coins[i]]==false)
                        {
                            qu.push(temp-coins[i]);
                            v[temp-coins[i]]=true;
                        }
                    }
                    else break;//因为排序了，如果减去当前的硬币值都是负数的话，减后面的硬币肯定是负数，直接break剪
                }
                size--;
            }
        }
    }
};
```