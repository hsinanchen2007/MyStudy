### 解题思路
简单的map或set使用

### 代码

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res=0;
        int n=nums.size();
        if(n<2||k<0)return 0;
        if(k==0)
        {
            unordered_map<int,int> m;
            for(int &num:nums)
            {
                ++m[num];
            }
            for(unordered_map<int,int>::iterator it=m.begin();it!=m.end();++it)
            {
                if(it->second>1)
                    ++res;
            }
        }
        else
        {
            set<int> s(nums.begin(),nums.end());

            for(set<int>::iterator i=s.begin();i!=s.end();++i)
            {
                if(s.count((*i)+k)!=0)++res;
            }
        }
        return res;
    }
};
```