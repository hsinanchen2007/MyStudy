### 解题思路
思路一当然是递归法，直接使用公式递归即可，但当递归层数较多时，一是递归栈内存开销大，二是递归操作的时间消耗非常大，不实用。
思路二是空间换时间，使用一个数组存储计算出的斐波那契数，再返回第n个数即可。
### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        std::vector<int> vec = {0, 1};

        for(int i = 2; i <= n; i++){
            vec.push_back((vec[i-2]+vec[i-1])%1000000007);
        }

        return vec[n];
    }
};
```