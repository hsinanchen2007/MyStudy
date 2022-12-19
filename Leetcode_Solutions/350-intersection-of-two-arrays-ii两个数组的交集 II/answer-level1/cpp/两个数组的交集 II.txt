### 算法分析
1. 使用哈希表，遍历数组nums1记录整数和计数
2. 遍历数组num2,num=nums2[i]
3. 如果num存在于哈希表并且计数大于0，将计数递减并将num加入结果数组
4. 遍历结束，返回结果数组
### 复杂度分析
+ 时间复杂度：O(n)，n最小数组长度
+ 空间复杂度：O(n)，哈希表占用额外空间
### 源码
```C++ []
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        unordered_map<int, int> hashMap;
        vector<int> result;

        for (auto &&num : nums1)
        {
            if (hashMap.count(num))
            {
                ++hashMap[num];
            }
            else
            {
                hashMap[num] = 1;
            }            
        }
        
        for (auto &&num : nums2)
        {
            auto iter = hashMap.find(num);
            if (iter != hashMap.end() && iter->second > 0)
            {
                --iter->second;
                result.push_back(num);
            }
        }
        
        return result;
    }
};