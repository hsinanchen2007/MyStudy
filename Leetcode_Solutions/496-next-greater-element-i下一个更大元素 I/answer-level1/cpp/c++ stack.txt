### 解题思路
不完全单调栈

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        unordered_map<int,int> hash;
        stack<int> s;
        for(int i = 0;i < nums1.size();++i)hash[nums1[i]] = i;
        for(int i = nums2.size()-1;i >= 0;--i){
            if(hash.count(nums2[i])){
                while(!s.empty() && nums2[i] >= s.top())s.pop();
                if(s.empty())
                    ans[hash[nums2[i]]] = -1;
                else ans[hash[nums2[i]]] = s.top();
            }
            s.push(nums2[i]);
        }
        return ans;
    }
};
```