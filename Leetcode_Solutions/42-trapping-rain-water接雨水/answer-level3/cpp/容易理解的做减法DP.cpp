### 解题思路
dp[i]定义：从0到i，所有柱子高度值以及所包含的所有水滴之和，最终结果为：dp[len-1] - 所有柱子的总和

状态转移分两种情况
1，当前height[i]的高度小于等于height[i-1]，那么水滴没增加，柱子增加：dp[i] = dp[i - 1] + height[i];
2，当前height[i]的大于height[i-1]，需要辅助变量，记录height的前i-1中最大值max_val(历史最高的柱子值)及其对应的max_index，比较height[i]和max_val，存在两种情况：
  2.1，如果height[i] > max_val，那么dp[i]的值为dp[max_index]加上一个矩形(因为dp[i]定义是水滴和柱子和，单独求水滴做dp情况有点太多)，这个应该很容易理解
    dp[i] = dp[mav_index] + (i - mav_index) * max_val + height[i] - max_val;
  2.2，如果height[i] <= max_val，那么只需向前找到第一个大于等于height[i]的索引(**可以用单调栈**)，然后更新dp[i]
    dp[i] = dp[ge_index] + (i - ge_index) * height[i]; 

执行用时 :4 ms, 在所有 C++ 提交中击败了94.75%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    class node {
      public:
        int value;
        int index;
        node(int val, int idx) {
          value = val;
          index = idx;
        }
    };

    int trap(vector<int>& height) {
      // 前两个怎么都没有水滴
      int len = height.size();
      if (len <= 2) {
        return 0;
      }

      int sum = height[0];  // 存储所有的柱子和
      int max_val = height[0];  // 存储最高柱子值
      int mav_index = 0;  // 存储最高柱子值对应的index
      vector<int> dp(len, 0); // 初始化dp数组
      stack<node> monotone;
      dp[0] = height[0];
      monotone.push(node(height[0], 0));

      // 前两个元素更新各个变量
      if (height[0] <= height[1]) {
        mav_index = 1;
        max_val = max(height[0], height[1]);
        monotone.pop();
      }
      dp[1] = dp[0] + height[1];
      sum += height[1];
      monotone.push(node(height[1], 1));
      
      int i = 2;
      
      for (; i < len; ++i) {
        sum += height[i]; // 累加记录即可
        if (height[i] <= height[i - 1]) {
          dp[i] = dp[i - 1] + height[i];  // 此时水滴无新增
        } else {
          if (max_val >= height[i]) {
            int ge_index = mav_index;
            while (!monotone.empty()) {
              if (monotone.top().value < height[i]) {
                monotone.pop();
              } else {
                break;
              }
            }
            ge_index = monotone.top().index;
            dp[i] = dp[ge_index] + (i - ge_index) * height[i];
          } else {
            dp[i] = dp[mav_index] + (i - mav_index) * max_val + height[i] - max_val;
          }
        }

        if (max_val <= height[i]) {
          max_val = height[i];
          mav_index = i;
        }

        while (!monotone.empty()) {
          if (monotone.top().value <= height[i]) {
            monotone.pop();
          } else {
            break;
          }
        }
        monotone.push(node(height[i], i));
      }

      return dp[len - 1] - sum;
    }
};
```