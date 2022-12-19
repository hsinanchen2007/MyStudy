### 解题思路
绝大多数思路来自官方题解第三，看完后觉得太巧妙了！为此加上注释并且修改变量名使得可读性更强一些。

### 代码

```cpp
class Solution {
public:
    vector<int> nums;
    int m;
    int splitArray(vector<int>& nums, int m) {
        this->nums = nums;
        this->m = m;
        
        // 这一步计算分割的最小可能性和最大可能性
        // 最小可能性：单独一个元素为数组，最大值就是数组最大的元素 （minSum）
        // 最大可能性：不分割数组，那么就是数组的总和（maxSum）
        // 答案的可行解区域就在这之中，可以进行二分搜索
        // （最差不会超过64次搜索，实际上更小一点，最差情况是44次，log(10000*INT_MAX)）
        long long int minSum = 0, maxSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxSum += nums[i];
            if (minSum < nums[i]) minSum = nums[i];
        }
        
        long long int mid; // , ans = maxSum;
        while (minSum < maxSum) {
            // 模板二，官方题解还多了一步min其实没必要
            // while条件相比官方题解少了判断== 所以循环结束条件就是left==right
            // 因为二分每个元素遍历到，最后的min/max值一定是答案
            mid = (maxSum + minSum) / 2; // 这里不用防止溢出了，数值远低于LL能保存的最大值
            if (possible(mid)) {  // 二分查找
                // ans = min(ans, mid); // 官方题解多余的步骤
                maxSum = mid; // 相比官方题解少了-1
            } else {
                minSum = mid + 1;
            }
        }
        return maxSum;
    }
    
    bool possible(int guess) {
        // 贪心算法，太巧妙了！
        // 遍历整个数组，凑数字！凑齐guess的数字后就丢掉，继续凑下一组
        // 然后计算count的数量是否比m小！换句话说就是凑出这个数字的数组数量够不够m个
        // 如果小的话，证明guess太大了，需要往左边再继续找
        // 否则就是guess太小了，往右边继续找
        long long int sum = 0;
        int count = 1;            
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > guess) {
                ++count;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return count <= m;
    }
};
```