### 解题思路
用八皇后问题的方法产生
[0, 0, 0]
[0, 0, 1]
[0, 1, 0]
[0, 1, 1]
[1, 0, 0]
[1, 0, 1]
[1, 1, 0]
[1, 1, 1]
的序列，然后1和0对应着nums里的数字是否加到集合中

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> used(nums.size(), 0);
        vector<int> bitemp(nums.size(), 0);

        f(ret, nums, used, bitemp, 0); 

        return ret;
    }

    // 递归函数，bitemp用来存放生成的bit序列，used数组防止重复使用同一level。
    void f(vector<vector<int>>& ret, vector<int>& nums, vector<int>& used,
           vector<int>& bitemp, int level) {
        if (level == nums.size()) {// 递归终点，将bit序列转换成子集。
            vector<int> temp;
            for (int i = 0; i < nums.size(); ++i) {
                if (bitemp[i]) {
                    temp.push_back(nums[i]);
                }
            }
            ret.push_back(temp);
            return ;
        }

        // 将每一level的位置尝试0、1，使用过的位置used标记为1。
        for (int i = 0; i <= 1; ++i) {
            if (!used[level]) {
                bitemp[level] = i;
                used[level] = 1;

                f(ret, nums, used, bitemp, level + 1);

                used[level] = 0;
            }
        }
    }
};
```