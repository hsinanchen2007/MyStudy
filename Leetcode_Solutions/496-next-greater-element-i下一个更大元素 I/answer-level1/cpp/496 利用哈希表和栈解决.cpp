### 解题思路
利用哈希表和栈
1，遍历nums2，构建单调栈，如果元素有下一个最大元素，将其录入哈希表中；
2，根据哈希表，输出nums1的下一个更大元素，如果没有就输出-1。
### 头文件
```
#include <vector>
#include <stack>
#include <map>
```
### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty())
            return {};
        vector<int> ans;

        //遍历nums2，如果元素有下一个最大元素，将其录入哈希表中。
        stack<int> s;
        map<int, int> map;
        int len2 = nums2.size();
        for (int i=0; i<len2; i++) {
            if (s.empty()) {
                s.push(nums2[i]);
            }
            else {
                while (!s.empty()) {
                    if (nums2[i] > s.top()) {
                        map[s.top()] = nums2[i];
                        s.pop();
                    }
                    else
                        break;
                }
                s.push(nums2[i]);
            }
        }

        //输出nums1的下一个更大元素
        int len1 = nums1.size();       
        for (int j=0; j<len1; j++) {
            if (map.find(nums1[j]) != map.end()) {
                ans.push_back(map[nums1[j]]);
            }
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
```