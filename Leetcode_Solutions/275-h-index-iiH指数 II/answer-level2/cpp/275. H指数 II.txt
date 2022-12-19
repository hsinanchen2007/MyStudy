### 解题思路
不用排序那还有什么可做的……懒得写二分了……

### 代码

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        for(int i=0;i<n;++i)
        {
            if(citations[n-1-i]<=i)
            {
                return i;
            }
        }
        return n;
    }
};
```