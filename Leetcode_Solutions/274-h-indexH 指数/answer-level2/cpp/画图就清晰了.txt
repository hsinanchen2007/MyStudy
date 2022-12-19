### 解题思路
从大到小排序，其实就是求点集里最大的一个正方形

### 代码

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int i=0;
        while (i != citations.size()) {
            if (i+1 > citations[i]) break;
            i++;
        }
        return i;
    }
};
```