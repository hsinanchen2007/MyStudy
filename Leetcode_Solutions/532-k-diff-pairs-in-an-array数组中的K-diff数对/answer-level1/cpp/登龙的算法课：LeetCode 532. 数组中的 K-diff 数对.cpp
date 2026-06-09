### 一、题目描述
给定一个整数数组和一个整数 k, 你需要在数组里找到不同的 k-diff 数对。这里将 k-diff 数对定义为一个整数对 (i, j), 其中 i 和 j 都是数组中的数字，且两数之差的绝对值是 k。

示例 1:

- 输入: [3, 1, 4, 1, 5], k = 2
- 输出: 2

解释: 数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。尽管数组中有两个 1，但我们只应返回不同的数对的数量。

### 二、解题思路
利用两个数的绝对值之差为 k 的关系 x - y = k，推出 y = x - k 和 x = y + k：
- saw 集合保存访问过的元素
- diff 集合保存已找到的 k-diff 数对中的较小值
- 遍历所有元素，判断当前元素是否符合下面 2 个条件之一
- 如果 y = x - k (1 = 3 - 2) 在 saw 中，则在 diff 中加入较小值 x - k = 1
- 如果 x = y + k (3 = 1 + 2)在 saw 中，则在 diff 中加入较小值 y = 1
- 在 saw 中加入已访问的元素
- 放回 diff 集合的大小（set 相同的元素只存放一次）

要注意 set 中相同的元素只存放一次，所以对于 3 1 4 1 5 的情况，diff 集合中只会保存 1 个元素 1，表示只有一个 (1, 3) 数对。


```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      if (k < 0)
        return 0;
      
      // 保存访问的元素
      std::set<int> saw;

      // 保存 k-diff 数对中较小的那个（也可以保存较大的）只用来统计数对个数
      std::set<int> diff;

      for (int i = 0; i < nums.size(); i++) {
        // 检查数对中较小的数 1 是否在数组中：3 - 2 = 1
        if (saw.find(nums[i] - k) != saw.end())
          diff.insert(nums[i] - k); // 插入数对中较小的数 1
        
        // 检查数对中较大的数 3 是否在数组中：1 + 2 = 3
        if (saw.find(nums[i] + k) != saw.end())
          diff.insert(nums[i]); // 插入数对中较小的数 1
        
        saw.insert(nums[i]);
      }

      // 因为 set 中不存在重复元素，所以不同的元素个数代表不同的 k-diff 数对个数
      return diff.size();
    }
};
```

#### 复杂度分析
- 时间复杂度：O(n)，只需要遍历一次数组
- 空间复杂度：O(n)，set 集合空间与数组大小 n 呈线性增长


### 三、最后
感谢你的阅读，如果文章对你有帮助，可以扫描下方二维码或者微信搜索「登龙」，关注公众号「登龙」查看更多人工智能、编程算法等技术干货！也可以访问我的个人博客：[登龙的技术博客](https://dlonng.com/) 感谢支持！

![](https://pic.leetcode-cn.com/38d3abae6e2b38daa6f52898299c049049d82787f9b1c46345b48fc6f711889e.png)