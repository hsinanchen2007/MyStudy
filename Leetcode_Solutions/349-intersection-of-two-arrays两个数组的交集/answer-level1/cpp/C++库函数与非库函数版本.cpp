首发于公众号：算法工程师之路
直接使用STL算法中的set操作函数，注意set有关的函数必须在排序序列中使用，因此必须先排序！然后使用unique函数去重即可！

（STL库函数版本）
```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(res));
        auto it = unique(res.begin(), res.end());
        res.erase(it, res.end());
        return res;
    }
};
```
（非库函数版本）
```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i = 0; i < nums1.size(); i ++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    res.push_back(nums1[i]);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        auto it = unique(res.begin(), res.end());
        res.erase(it, res.end());
        return res;
    }
};
```
