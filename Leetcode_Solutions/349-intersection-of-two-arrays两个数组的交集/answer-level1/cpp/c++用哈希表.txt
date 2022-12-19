### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1;
        vector<int> ans;
        for(int i:nums1){
            if(n1.count(i)<=0) n1.insert(i);
        }
        for(int j:nums2){
            if(n1.find(j)!=n1.end()){
                ans.push_back(j);
                n1.erase(j);//保证不会再有一个j放进来
            }
        }
        return ans;

    }
};
```