### 解题思路
本题第一眼看上去有两种方法：
1、排序之后，输出中位数
2、建立哈希表，遍历哈希表，输出最大的

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[(int)nums.size()/2];
    }
};
```