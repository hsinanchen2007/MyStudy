用C++的multiset容器
执行用时 :4 ms, 在所有 C++ 提交中击败了86.16%的用户
内存消耗 :8.8 MB, 在所有 C++ 提交中击败了100.00%的用户

```
class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        int ans=0;
        int len=heights.size();
        multiset<int> sort;
        int i=0;
        for(;i<len;i++)
        {
            sort.insert(heights[i]);
        }
        i=0;
        for(auto it=sort.begin();it!=sort.end();it++)
        {
            if(*it!=heights[i])
            {
                ans++;
            }
            i++;
        }
        return ans;
    }
};
```
