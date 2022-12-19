### 解题思路
因为要求N-h篇不多于h次，其实就相当于左边要满足所有数字小于等于h，并且要找到这个的最右边界（如果 h 有多种可能的值，h 指数是其中最大的那个。），所以就是找大于左边所有的第一个位置，也就是upper_bound，所以right要设置为size()而不是size()-1。

### 代码

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int left = 0, right = citations.size();
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(citations[mid] >= citations.size() - mid)
                right = mid;
            else
                left = mid + 1;
        }
        return citations.size() - left;
    }
};
```