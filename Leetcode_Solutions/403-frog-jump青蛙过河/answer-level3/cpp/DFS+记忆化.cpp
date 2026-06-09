### 解题思路

递归思路：
1、在某个位置，假设上一步跳跃为k个单位，那么当前这一步可以跳跃k+1, k-1, k个单位
2、递归退出条件，当前跳跃到达位置为石头列表中最后一位，能到达则表示成功
3、暂定记忆化数组为在第i个石子上跳跃k个单位的结果

164ms 18.8M
--- wangtao HW-2020/3/1

### 代码

```cpp
class Solution {
public:
    int d[3] = {-1, 0, 1};
    bool crossDFS(map<pair<int, int>, int>& mem, set<int>& stone, int lastk, int curstone, int dststone)
    {
        if (mem.count({lastk, curstone}) != 0) return false;
        if (curstone == dststone) {
            return true;
        }
        for (int i = 0; i < 3; i++) {
            int newk = lastk + d[i];
            int newstone = curstone + newk;
            if (newk > 0 && stone.count(newstone) != 0) {
                if (crossDFS(mem, stone, newk, newstone, dststone)) {
                    return true;
                } else {
                    mem[{newk, newstone}] = 1;
                }
            }
        }
        return false;
    }

    bool canCross(vector<int>& stones) {
        int dststone = *stones.rbegin();
        set<int> stone;
        map<pair<int, int>, int> mem;
        for (int c : stones) {
            stone.insert(c);
        }
        // 第一步固定了步数需要做识别，决定是否开始遍历计算
        if (stone.count(1 + stones[0]) == 0) return false;
        return crossDFS(mem, stone, 1, stones[0], dststone);
    }
};
```