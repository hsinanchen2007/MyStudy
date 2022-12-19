```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        for(int i = 0; i < nums1.size(); ++i) { 
            s1.insert(nums1[i]);
        }
        set<int> s2;
        for(int j = 0; j < nums2.size(); ++j) {
            if(s1.find(nums2[j]) != s1.end())
            s2.insert(nums2[j]);
        }
        vector<int> x;
        for(auto iter = s2.begin(); iter != s2.end(); ++iter) {
            x.push_back(*iter);
        }
        return x;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8fdbe927d6563f69c4f895c6253c50db77e6511c85079298186155cdf8ee9cc8-image.png)
