### 解题思路
使用普通遍历会超时，这里使用`unordered_map`。它是一种`hash_map`

- 无序映射是关联容器，用于存储由键值和映射值组合而成的元素，并允许基于键快速检索各个元素
- `unordered_map`容器比映射容器更快地通过它们的键来访问各个元素
- 如果需要得到一个有序序列，使用红黑树系列的关联式容器，如果需要更高的查询效率，使用以哈希表为底层的关联式容器。 
- 在C++11中有新出4个关联式容器：`unordered_map`/`unordered_set`/`unordered_multimap`/`unordered_multiset`，它们与`map/multimap`/`set`/`multiset`功能基本类似，最主要就是底层结构不同，使用场景不容。

### 代码

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_map<int,int> mp;
       mp.clear();
       for(int i:nums)
       {
           mp[i]++;
           if(mp[i]>1)
            return true;
       }
        return false;
    }
};
```