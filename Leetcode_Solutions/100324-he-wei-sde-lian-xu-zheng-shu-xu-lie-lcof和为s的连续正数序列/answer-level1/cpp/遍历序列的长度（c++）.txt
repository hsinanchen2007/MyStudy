### 解题思路
对于一个长度为 k+1 的从 x 开始的连续正整数序列 $x, x+1, x+2, ..., x+k$ 进行分析：
由 $x+(x+1)+(x+2)+...+(x+k)=target$ 可以推出 
$x = \frac{2*target - k^2 - k}{2(k+1)}$
因为 x 的最小值是 1， 所以由 $2*target-k^2-k > 0$ 
可知 $k^2 < 2*target$, 可知 $k<\sqrt{2*target}$
所以，我们在 $[1, \sqrt{2*target})$ 范围内遍历 k，根据计算公式求 x，如果 x 为整数，则找到一个合适的序列。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        for(int k = sqrt(2*target); k > 0; --k){
            int t = target*2 - k*k - k;
            int x = t / 2 / (k+1);
            if(x > 0 && 2*(k+1)*x == t){
                vector<int> temp;
                for(int i = 0; i <= k; ++i){
                    temp.push_back(x+i);
                }
                vec.push_back(temp);
            }
        }
        return vec;
    }
};
```