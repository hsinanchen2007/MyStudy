```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int tmp = 0;
        for (auto a2 : arr2)
            for (auto& a1 : arr1)
                if (a1 == a2) swap(a1, arr1[tmp++]);

        sort(arr1.begin() + tmp, arr1.end());
        return arr1;
    }
};
```