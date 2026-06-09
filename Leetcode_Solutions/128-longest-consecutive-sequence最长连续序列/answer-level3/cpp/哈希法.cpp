将数组进行哈希，对于每一个元素向左向右扩展，在扩展的过程中把遍历的元素也删除（因为一个序列上的每个元素的遍历结果相同）。并更新最大长度。
```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_v = 0;
        for(auto i: nums){
            int l = i, r = i + 1;
            while(num_set.count(l))
                num_set.erase(l--);
            while(num_set.count(r))
                num_set.erase(r++);
            max_v = max(max_v, r - l - 1);
        }
        return max_v;
    }
};
```