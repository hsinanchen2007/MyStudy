### 解题思路
降序排列

### 代码

```cpp
bool myfunction (int i,int j) { return (i>j); }

class Solution {
public:
    int hIndex(vector<int>& citations) {
        stable_sort(citations.begin(),citations.end(),myfunction);

        int n=citations.size();
        for(int i=0;i<n;++i)
        {
            if(citations[i]<=i)
            {
                return i;
            }
        }
        return n;
    }
};
```