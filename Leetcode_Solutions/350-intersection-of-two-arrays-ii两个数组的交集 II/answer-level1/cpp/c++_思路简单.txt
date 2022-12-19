```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp1, mp2;
        for (int i = 0; i < nums1.size(); i++)
            mp1[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++){
            if (mp1[nums2[i]] > 0)
                mp2[nums2[i]]++;      
        }
        for (int i = 0; i < nums2.size(); i++){
            if (mp2[nums2[i]] > 0){
                for (int j = 0; j < min(mp1[nums2[i]], mp2[nums2[i]]); j++)
                    res.push_back(nums2[i]);
                mp2[nums2[i]] = 0;
            }
        }
        return res;
    }
};
```
改进之后：

```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums1.size(); i++)
            mp[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++){
            if (mp[nums2[i]] > 0){
                res.push_back(nums2[i]);
                mp[nums2[i]]--;
            }    
        }
        return res;
    }
};
```

看了别人代码之后发现还可以优化一下：这样如果nums1.size()和nums2.size()相差很大的话，优势会很明显。（在第一个for循环赋初值时）
```
if(nums1.size()>nums2.size()) swap(nums1,nums2);//用元素少的数组元素查找
```
