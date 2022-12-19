# 思路

本题的优化目标是：一个团队中「所有工程师速度的和」乘「效率值中的最小值」。如果我们固定一个「效率值的下界」，那么为了使上式取得最大值，只需在当前可选的工程师中（他们的效率大于等于此下界），选出最大的 `k` 个。而全局的最优解为，枚举所有「效率值的下界」以后，找到的最大的「团队表现值」。

给定 `n` 个工程师的情况下，「效率值的下界」最多有 `n` 个。我们不妨先把所有工程师按照其效率值从小到大排序。这样在考虑排序后的第 `i` 个效率值时，`i` 及其以后的所有工程师都可选。换言之，`i` 之前的工程师都不可选。可选不可选，用一个布尔数组动态维护即可。

而为了在标记为「可选」的工程师中快速地找到速度最大的 `k` 个，我们不妨也先把所有工程师按照其速度值从大到小排序。那么在所有工程师都可选的情况下，显然前 `k` 个为所求的解集合。每当这 `k` 个工程师有一个被标记为「不可选」时，我们先在解集合中删除之，再顺着排序后的顺序，找到第一个标记为「可选」的工程师，把它加到此解集合中。而每一个解对应的「团队表现值」等于「所有工程师速度的和」乘上当前正在访问的「效率值的下界」。而「所有工程师速度的和」可以按照差值动态更新，即：减去删掉的，加上新加的。

最后，需要估算一下可能出现的最大「团队表现值」：$10^8 \times 10^5 \times 10^5 = 10^{18} < 2^{63}$，故用 `long long` 就不会溢出了！

# 复杂度分析

两次排序：$O(n \log n)$
求最大「团队表现值」：$O(n \log k + n)$，其中每访问一个效率值时，都要判定它对应的工程师是否在解集合中，这一步需要 $O(\log k)$（如果直接开一个布尔数组可以优化到常数）；而添加一个工程师到解集合时，所有人都被遍历一次，总计为$O(n)$
故整体复杂度：$O(n \log n)$

# 代码

```c++
struct person1 {
    int id;
    int eff;
    person1(int i, int e) : id(i), eff(e) {}
};

struct person2 {
    int id;
    int sp;
    person2(int i, int s) : id(i), sp(s) {}
};

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<person1> v1;
        vector<person2> v2;
        for (int i = 0; i < n; i++) {
            v1.push_back(person1(i, efficiency[i]));
            v2.push_back(person2(i, speed[i]));
        }
        
        // 按照效率排序
        sort(v1.begin(), v1.end(), [](const auto & p1, const auto & p2) {
            return p1.eff < p2.eff;
        });

        // 按照速度排序
        sort(v2.begin(), v2.end(), [](const auto & p1, const auto & p2) {
            return p1.sp > p2.sp;
        });
        
        // 解集合
        set<int> choosen;
        // 解集合中工程师的速度值之和
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            choosen.insert(v2[i].id);
            sum += v2[i].sp;
        }
        // 下一个待加入的工程师在 v2 中的下标
        int next = (k < n) ? k : -1;
        // 全局最优解
        long long best = 0;
        // 当前该工程师是否可选？
        vector<bool> valid(n, true);

        for (const auto & p : v1) {
            // 考虑按照 `p.eff` 作为效率值下界
            if (sum * p.eff > best) { // 更新全局最优解
                best = sum * p.eff;
            }
            
            // 在考虑下一个值之前，令此工程师不可选
            valid[p.id] = false;
            // 并动态更新解集合，及其中的工程师的速度值之和
            auto it = choosen.find(p.id);
            if (it != choosen.end()) {
                choosen.erase(it);
                sum -= speed[p.id];
                
                while (next != -1 && !valid[v2[next].id]) {
                    next = (next + 1 < n) ? (next + 1) : -1;
                }
                if (next != -1) {
                    choosen.insert(v2[next].id);
                    sum += v2[next].sp;
                    
                    next = (next + 1 < n) ? (next + 1) : -1;
                }
            }
        }
        
        return best % 1000000007;
    }
};
```
