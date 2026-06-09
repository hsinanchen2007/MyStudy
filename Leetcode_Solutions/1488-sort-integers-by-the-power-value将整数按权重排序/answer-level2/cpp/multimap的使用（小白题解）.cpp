
### 代码

```cpp
class Solution {
public:
    int getKth(int lo, int hi, int k) 
    {
        //利用multimap的自动排序功能
        multimap<int,int> use;//记录每个数字的权重以及该数字本身

        for(int i=lo;i<=hi;i++)
            use.insert(pair<int,int>(help(i),i));

        vector<int> ans;
        for(auto u:use) ans.push_back(u.second);

        return ans[k-1];
    }

    //计算数字权重的函数
    int help(int num)
    {
        int ans=0;

        while(num!=1)
        {
            if(num%2==1) num=3*num+1;
            else num>>=1;
            ans++;
        }

        return ans;
    }
};
```