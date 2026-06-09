### 解题思路
（1）从一个点调到一个点是一个坐标型动态规划；
四步走：
（1）state 能和不能 所以是取 && 
（2）方程：f[j] = f[i] && f[i] >= j - 1 其中 i >= 0 && i < j
（3）初始化，0位置一定为true。其他位置为false；
（4）结果：球最后一个位置
注意点儿：
    （1）int j = i - 1; j >= 0; j--  从后往前可以加速；
    （2）break,位置意思是找到一个就行， 也可以加速；

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> vec(nums.size(), false);
        // 初始化 第一个位置一定true，其他位置初始化为false;
        vec[0] = true;
        // 状态转移函数 f[j] = (f[i]为true && j - i <= f[i]) 其中 ：0< i < j
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                // cout<<i<<":"<<((i - j) <= vec[j])<<endl;
                if (vec[j] && ((i - j) <= nums[j])) {
                    vec[i] = true;
                    break;
                }
            }
        }
        // 答案
        return vec[nums.size() - 1]; 
    }
};
```