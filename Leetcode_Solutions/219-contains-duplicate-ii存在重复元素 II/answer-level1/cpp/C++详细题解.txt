### 题意
只要重复元素的最后两个的索引的差的绝对值不大于k，就返回true

即（1，0，1，1） 因为最后两个索引（2和3）的差的绝对值不大于k，返回true
### 思路
使用一个哈希映射temp来记录当前元素的上一次映射，当元素重复两次以上，hashmap可以用temp来更新为当前元素的上一次映射的索引。

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        unordered_map<int,int> temp; //用来记录当前元素的上一次映射
        for(int i = 0; i < nums.size(); ++ i){
            if(hashmap.count(nums[i])){
                if(!temp.count(nums[i]))    temp[nums[i]] = i;
                else{
                    hashmap[nums[i]] = temp[nums[i]];
                    temp.erase(nums[i]);
                }
                if(i - hashmap[nums[i]] <= k)   return true;
            }
            else    hashmap[nums[i]] = i;
        }
        return false;
    }
};
```
