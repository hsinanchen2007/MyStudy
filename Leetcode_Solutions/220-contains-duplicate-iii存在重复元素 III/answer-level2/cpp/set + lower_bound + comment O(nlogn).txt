时间: O(nlogn)
空间: O(k)
```cpp
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // 活动窗口
        set<int> record;
        for(int i=0; i<nums.size(); i++){
            // 找到大于或等于nums[i]-t的数中最小的数
            auto s = record.lower_bound((double)nums[i]-t); // 防溢出
            // 存在大于或等于nums[i]-t的数 && 这个数不比nums[i]+t大
            if(s != record.end() && *s <= (double)nums[i]+t)
                return true;
            // i-j的最大值是k, 也就是record的最大长度可以是k+1
            // 将当前元素插入record
            // insert放在这里而是不在上个if之前, 是为了防止lower_bound取到的元素和nums[i]一样
            record.insert(nums[i]);
            // record.size保持<=k+1
            // 当record达到k+1时, 马上要删去一个, 为下一个元素腾出空间
            if(record.size() == k+1)
                record.erase(nums[i-k]);
        }
        return false;
    }
```

如果有写得不清楚的, 欢迎提出来
大家一起交流!
