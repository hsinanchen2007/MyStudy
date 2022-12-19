### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr.size());
        int m = -1;   //记录最大值
        //从后往前扫描
        for(int i = arr.size() - 1; i >= 0; i--)
        {
            ans[i] = m;
            m = max(m, arr[i]);
        }
        return ans;
    }
};
```