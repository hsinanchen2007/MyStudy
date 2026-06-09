
### 代码

```cpp
class Solution {
public:
    int countLargestGroup(int n) 
    {
        int ans=0;
        unordered_map<int,vector<int>> use;//将同数位和的数字放在一起
        for(int i=1;i<=n;i++)
            use[help(i)].push_back(i);
        
        int l=0;//记录同数位和数组的最大长度
        for(auto u:use)
        {
            if(u.second.size()>l)
            {
                l=u.second.size();
                ans=1;
            }
            else if(u.second.size()==l)
                ans++;
        }
        
        return ans;
    }

    //计算每个数字的数位和
    int help(int num)
    {
        int res=0;
        while(num)
        {
            res+=num%10;
            num/=10;
        }
        return res;
    }
};
```