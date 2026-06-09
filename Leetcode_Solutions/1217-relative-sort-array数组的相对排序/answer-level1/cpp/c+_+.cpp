### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        vector<int> a(1010, 0);    

        for(auto t : arr1) ++a[t];

        for(auto t : arr2)
            while(a[t]--) ans.push_back(t);

        for(int i = 0;i < a.size();++i)
            while(a[i] > 0 && a[i]--) ans.push_back(i);

        return ans;
    }
};
```