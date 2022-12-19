### 解题思路
此处撰写解题思路
根据初始序列 “1” 递推至第n个序列，执行用时 4ms 内存 8.9M ，内存可以继续优化下，因为我把每个递推序列都保存了，其是没必要

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        vector<string> v;
        v.push_back("1");  //初始序列
        for(int i = 1;i<n;++i)  //根据前置序列推出下一序列
        {
            string s = "";
            int count = 1;
            stringstream ss;
            char c = v[i-1][0];
            for(int j = 1;j<v[i-1].size();++j)
            {
                if(c==v[i-1][j])
                {
                    count++;
                }
                else
                {
                    ss<<count<<c;
                    count = 1;
                    c = v[i-1][j];
                }
            }
            ss<<count<<c;
            ss>>s;
            v.push_back(s);
        }
        return v[n-1];
    }
};
```