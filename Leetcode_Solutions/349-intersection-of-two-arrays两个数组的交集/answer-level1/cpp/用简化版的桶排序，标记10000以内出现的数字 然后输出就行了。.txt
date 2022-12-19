4ms


```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        int a[10000] = {0};
        int b[10000] = {0};
        int k = 0;
        for(int i = 0; i < nums1.size(); i++)
        a[nums1[i]]++;
        for(int j = 0; j < nums2.size(); j++)
        b[nums2[j]]++;
        for(int i = 0; i < 10000; i++)
        if(a[i] > 0 && b[i] > 0)
        v.push_back(i);
        return v;
    }
};
```