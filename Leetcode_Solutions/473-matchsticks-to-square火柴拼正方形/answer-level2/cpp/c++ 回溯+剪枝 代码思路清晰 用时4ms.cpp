### 解题思路
dfs，回溯+记忆化，用一个访问数组记录访问路径可以很大程度上剪枝。具体实现见代码
思路参考了[C++ 递归回溯](https://leetcode-cn.com/problems/matchsticks-to-square/solution/c-di-gui-hui-su-by-ekulelu/)
### 代码

```cpp
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return false;

        int s = accumulate(nums.begin(), nums.end(), 0);
        if(s % 4 != 0) return false; //特判，若火柴不足四根或总长度不能分成四份，直接返回。

        int edge = s / 4, ans = 0;
        vector<bool> visited(n, false);
        sort(nums.begin(), nums.end());//排序是回溯的前提

        //从后往前找，贪心
        for(int i = n-1; i >= 0; i--){
            if(visited[i]) continue;//剪枝
            if(find(nums, visited, i, edge)){
                ans++;
                if(ans == 3) return true;//已经找到三条边就可以直接返回，剩下的必然可以组成最后一条，剪枝
            }
        }

        return false;//若遍历完都没找够三条边 说明不可能
    }

    bool find(vector<int>& nums, vector<bool>& visited, int idx, int target){
        if(target == 0) return true;

        int last = -1;// 
        for(int i = idx; i >= 0; i--){
            if(visited[i]) continue;

            int t = target - nums[i];
            if(last == t || t < 0) continue;// 该目标递归过或者长度过长，直接跳过

            visited[i] = true;
            last = t;
            if(find(nums, visited, i-1, last)) return true;
            else visited[i] = false; // 回溯
        }
        return false;
    }
};
```