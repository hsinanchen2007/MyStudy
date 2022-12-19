### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size() == 0)return {};
        vector<int> left(a.size(), 1);
        vector<int> right(a.size(), 1);
        vector<int> res(a.size(), 1);
        for(int i = 1; i < a.size(); ++i)
        {
            left[i] = left[i-1] * a[i-1];  //left[i]表示a[i]左侧的乘积(不包括a[i])
            right[a.size()-i-1] = right[a.size()-i] * a[a.size()-i];  //right[n-i-1]表示a[n-i-1]右侧的乘积(不包括a[n-i-1])
        }
        for(int i = 0; i < a.size(); ++i)
        {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};
```