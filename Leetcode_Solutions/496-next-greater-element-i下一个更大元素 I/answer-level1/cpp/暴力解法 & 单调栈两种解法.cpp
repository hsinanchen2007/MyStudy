### 解法一 暴力解法
  对于`nums1`的每个元素，在`nums2`中找到它，假设它的下标为`i`，那么从第`i+1`位开始搜索是否存在比它大的，找到就将该值加入记录中，否则加入`-1`

### 解法一代码

```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int n: nums1){
            int i = 0;
            while(nums2[i] != n) i++;
            i++;
            for(;i<nums2.size();i++){
                if(nums2[i] > n){
                    res.push_back(nums2[i]);
                    break;
                }
            }
            if(i == nums2.size()) res.push_back(-1);
        }
        return res;
    }
};
```


### 解法二 单调栈
  对于`nums2`的元素，维护一个单调不增的栈。依次扫描`nums2`的元素，假如扫到第`i`位，而且当前栈顶元素小于第`i`位元素，则栈顶元素找到了下一个比它大的元素。将其记录到哈希表中。否则将第`i`位元素入栈。当扫描完`nums2`，留在栈中的元素都是没有比它大的元素存在的。最后，对于`nums1`的每个元素，依次查询哈希表即可得到他们的**下一个更大元素**

### 解法二代码
```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        stack<int> sk;
        for(int n: nums2){
            while(!sk.empty() && sk.top() < n){
                mp[sk.top()] = n;
                sk.pop();
            }
            sk.push(n);
        }
        while(!sk.empty()){
            mp[sk.top()] = -1;
            sk.pop();
        }
        for(int n: nums1){
            res.push_back(mp[n]);
        }
        return res;        
    }
};
```