### 解题思路
等差数列公式 ： (x+y)*(y-x+1)/2 = target; 
展开得：y^2 + y + (-x^2+x-2*target) = 0
求根公式：y = ( -1 + sqrt(1-4*(-x^2+x-2*target)) ) / 2;
判断条件：delta>0 and (x + y) * (y - x + 1) / 2 == target
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 创建返回的二维向量
        vector<vector<int>> vec;
        // 用于填充的一维向量
        vector<int> res;
        // 每组序列首个数字的上限
        int limit_x = target/2;
        // 开始枚举
        for(int x = 1; x<=limit_x; ++x){
            long delta = 1 - 4 * (-(long)x*x+x-2*target);
            if(delta > 0){
                int y = (-1 + sqrt(delta)) / 2;
                // 如果求和结果等于target
                if((x + y) * (y - x + 1) / 2 == target){
                    // 开始填充
                    res.clear();
                    for(int i = x; i<=y; ++i){
                        res.push_back(i);
                    }
                    vec.push_back(res);
                }
            }
        }
        return vec;
    }
};
```