### 解题思路
使用`unordered_map`记录键值对，key是元素的hash值，值是元素出现次数，根据hash值判断元素是否相同。
`unordered_map`与`map`的区别：储时是根据key的hash值判断元素是否相同，即unordered_map内部元素是无序的，而map中的元素是按照二叉搜索树存储。

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(int num : nums){
            cnt[num]++;
            if(cnt[num]>nums.size()/2)return num;
        }
        return -1;
    }
};
```