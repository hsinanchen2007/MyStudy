### 解题思路
利用两个人的糖果数满足的数学方程，来求获得交换糖果的等量关系。

设 x：爱丽丝给鲍勃的糖果数，y：鲍勃给爱丽丝的糖果数

因为两者最后的糖果数相同，所以有：
sum_a - x + y = sum_b + x - y -> y = x + (sum_b - sum_a) / 2

详细过程见注释，用到了 set 集合来判断集合 B 中是否存在对应元素。
### 代码

```cpp
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_a = 0;
        int sum_b = 0;

        std::set<int> set_b;

        // 1. 计算总和
        for (auto a : A) sum_a += a;

        for (auto b : B) {
            sum_b += b;
            set_b.insert(b);
        }

        // 2. x：爱丽丝给鲍勃的糖果数，y：鲍勃给爱丽丝的糖果数，两者最后的糖果数相同：
        // sum_a - x + y = sum_b + x - y -> y = x + (sum_b - sum_a) / 2
        int sum_ba = (sum_b - sum_a) / 2;

        for (auto x : A) {
            // 3. 如果 x + (sum_b - sum_a) / 2 在集合 B 中，则存在一对糖果数量符合条件
            if (set_b.find(x + sum_ba) != set_b.end())
                return vector<int>{ x, x + sum_ba };
        }

        return vector<int>{ 0, 0 };
    }
};
```