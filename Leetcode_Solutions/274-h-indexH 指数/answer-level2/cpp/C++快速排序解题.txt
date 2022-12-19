### 解题思路
利用快速排序将数组从大到小排序，然后顺序枚举即可。

### 代码

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0)
            return 0;
        sort(citations.begin(),citations.end(),greater<int>());
        int maxValue=0;
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=(i+1))
            {
                maxValue=i+1;
            }
        }
        return maxValue;
    }
};
```