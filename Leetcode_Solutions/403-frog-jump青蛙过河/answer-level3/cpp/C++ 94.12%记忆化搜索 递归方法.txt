关于本题其它方法及解析请移步blog：[[每日一题] 128. 青蛙过河(数组、记忆化搜索、递归、剪枝)](https://blog.csdn.net/yl_puyu/article/details/104221298)
- - **==使用记忆化搜索==，维护一个哈希表，建立青蛙在 pos 位置和拥有 jump 跳跃能力时是否能跳到对岸**
- **为了能用一个变量同时表示 pos 和 jump，可以将 jump 左移很多位并或上 pos**，[技巧:以唯一且确定性的方式将两个整数映射为一个](https://stackoverflow.com/questions/919612/mapping-two-integers-to-one-in-a-unique-and-deterministic-way)由于题目中对于位置大小有限制，int类型即可，不会产生冲突
- 首先判断 pos 是否已经到最后一个石头了，是的话直接返回 true
- 然后查看当前这种情况是否已经出现在哈希表中，是的话直接从哈希表中取结果
- 如果没有，就遍历余下的所有石头，对于遍历到的石头，计算到当前石头的距离 dist
- 如果 **dist 小于 jump - 1**，接着遍历下一块石头
- 如果 **dist 大于 jump + 1**，说明无法跳到下一块石头，m[key] 赋值为 false，并返回 false
- 如果在**青蛙能跳到的范围中，调用递归函数，以新位置 i 为 pos，距离 dist 为 jump，如果返回 true 了，即给 m[key] 赋值为 true，并返回 true**
- 如果结束遍历给 m[key] 赋值为 false，并返回 false
```cpp
// 执行用时 :40 ms, 在所有 C++ 提交中击败了94.12%的用户
// 内存消耗 :13.9 MB, 在所有 C++ 提交中击败了81.25%的用户

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> m;
        return help(stones, 0, 0, m);
    }

    bool help(vector<int>& stones, int pos, int jump, unordered_map<int, bool>& m) {
        int n = stones.size(), key = pos | jump << 11;
        if (pos >= n - 1) return true;
        if (m.count(key)) return m[key];
        for (int i = pos + 1; i < n; ++i) {
            int dist = stones[i] - stones[pos];
            if (dist < jump - 1) continue;
            if (dist > jump + 1) return m[key] = false;
            if (help(stones, i, dist, m)) return m[key] = true;
        }
        return m[key] = false;
    }
};
```