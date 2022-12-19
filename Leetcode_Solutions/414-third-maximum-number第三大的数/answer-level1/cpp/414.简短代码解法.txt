# 具体思路
说到寻找第几大的数第一时间就想到了排序，利用内置sort排序，然后unique去重容器将重复元素移至数组尾部，利用erase删除重复元素，最后对数组长度进行判断，如果长度小于3则返回数组最后一个元素，否则返回倒数第三个元素，至于时间复杂度和空间复杂度我就不分析了，各位有兴趣的可以看看

# 代码示例
```
class Solution {
public:
  int thirdMax(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int>::iterator it = unique(nums.begin(),nums.end());
    nums.erase(it,nums.end());
    if(nums.size() < 3)
    {
      return nums[nums.size() - 1];
    }
    return nums[nums.size() - 3];
  }
};
```
![屏幕快照 2019-12-02 上午10.11.38.png](https://pic.leetcode-cn.com/8b800ab7a1c1f4f054c90cb4a330f7ec409994b2bc0263ec0c4c9b32ad092b1c-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-02%20%E4%B8%8A%E5%8D%8810.11.38.png)
