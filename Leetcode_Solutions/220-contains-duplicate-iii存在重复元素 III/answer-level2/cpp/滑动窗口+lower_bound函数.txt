微信公众号：算法工程师之路
解题思路：

首先使用一个set作为一个滑动窗口，这样可以保证每个数的索引i和j之间差值小于等于k，然后另外一个条件是nums[i]和nums[j]的差的绝对值小于等于t，即
-t <= nums[i]-nums[j] <= t , 再进一步：
nums[i] - t <= nums[j] <= nums[i] + t，也就是说在set中找到满足这个式子的i, j就可以返回true了！
在STL库中，low_bound(type t)表示返回一个大于等于t的值，如果找不到就返回end()
因此在程序中，首先找到low_bound(nums[i]-t)，然后判断其是不是小于等于nums[i]+t，如果满足，则返回true，否则就继续移动长为k的滑动窗口寻找！

```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k < 1 || t < 0){
            return false;
        }
        int size = nums.size();
        if(size == 1)  return false;

        set<long long> s;
        int low = 0;
        for(int i = 0; i < size; i++){
            auto it = s.lower_bound((long long)nums[i]-t);
            if(it != s.end() && *it <= (long long)nums[i]+t){
                return true;
            }
            s.insert(nums[i]);     // 使得滑动窗口的大小不变
            if(s.size() == k+1){      
                s.erase(nums[low++]);
            }
        }
        return false;
    }
};
```
