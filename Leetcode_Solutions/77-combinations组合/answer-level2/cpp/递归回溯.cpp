### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
     vector<vector<int>> res;
     vector<int> vec;
     vector<int> a;
     int count = 0,len = n,pos = 0,i;
     for(i = 1;i<=n;i++)
     {
         a.push_back(i);
     }
     func(res,vec,k,count,pos,len,a);
     return res;
    }
    void func(vector<vector<int>>& res,vector<int>& vec,int k,int count,int pos,int len,vector<int>& a)
    {
        if(count == k)
        {
            res.push_back(vec);
            return ;
        }
        else
        {
            while(pos<len)
            {
                vec.push_back(a[pos]);
                ++count;
                func(res,vec,k,count,pos+1,len,a);
                vec.pop_back();
                --count;
                pos++;
            } 
        }
    }
};
```