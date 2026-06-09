### 解题思路
构造哈希表来储存重复了的元素及其下标。然后遍历数组如果发现
有重复：当前位置与上一个重复元素的下标（哈希表中已存）之差是否小于k。小于k，返回true，大于k，更新哈希表中该元素的下标。


### 代码

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>  hashmap;
        for(int i=0;i<nums.size();i++)
        {
            if(hashmap.count(nums[i])) //发现重复元素
            {
                if((i-hashmap[nums[i]])<=k)//满足条件，就返回
                    return true;
                else  //不满足
                {
                    hashmap[nums[i]]=i;  //更新重复元素nums[i]在哈希表中的最大下标
                }
            }
            else  //没发现重复元素
            {
                hashmap[nums[i]]=i;  //以该元素作为key，位置作为value
            }
        }
        return false;
    }
};
```