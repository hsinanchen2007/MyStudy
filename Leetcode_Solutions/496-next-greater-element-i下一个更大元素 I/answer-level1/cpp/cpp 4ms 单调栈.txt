![image.png](https://pic.leetcode-cn.com/b288fc13e239387a60d53f53a95048d044077f564eebb7e60c82f0094cd2db96-image.png)

思路：
1.从右向左遍历nums2
2.维护一个单调栈，即当前元素入栈前，所有比它小的都出栈，因为较小的必然不再是最近的
3.元素和最近的较大元素的映射用哈希表维护，接下来遍历nums1替换即可

```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> record;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty()) {
                if(s.top() > nums2[i]) {
                    record.emplace(nums2[i], s.top());
                    break;
                } else {
                    s.pop();
                }
            }
            if (s.empty()) {
                record.emplace(nums2[i], -1);
            }
            s.emplace(nums2[i]);
        }

        for (auto& num : nums1) {
            num = record[num];
        }
        return nums1;
    }
};
```
