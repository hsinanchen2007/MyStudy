## 思路
* 先统计所有数的个数为集合counts
* 对于集合counts中的数求这里面所有数的公约数X （X不能为1）
    * 因为X可以被所有数除尽。就可以分成X堆
    * 不妨求所有数的最大公约数

*PS: 对于所有非负数来说， 0与任何数X的最大公约数为X; 任何数都有公约数 `1和本身`; 辗转相除法对数的顺序没有要求*

### 哈希表实现

* 用哈希表统计每个元素个数
* 求所有个数的最大公约数

（LeetCode是debug模式，所以STL比较慢， 数据范围在[0, 10000]以内， 直接开个数组做也可以）

```cpp
class Solution {
public:
    int gcd(int a, int b) { // 求最大公约数
        return b ? gcd(b, a % b) : a;
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.empty()) return false;
        unordered_map<int, int> counts; 
        for (int x : deck) {   // 统计每一个数有多少个
            counts[x]++;
        }
        int X = 0;
        for (auto &kv : counts) {   // 求所有数的最大公约数
            X = gcd(X, kv.second);
            if (X == 1) return false;   // 剪枝：遇到1直接返回false
        }
        return true;
    }
};
```