### 解题思路
基本思路：
1. 题目要求为连续正数，所以其实是等差数列，已知target 求取该数列；
2. 遍历数列，对每个start求取其长度；

根据观察可以简化一部分处理：
1. 遍历过程可以减去一半，明显再target/2之后不会存在连续数列和为target；
2. 计算过程我们发现b*b-4*a*c永远为正数，所以可以抛去该值为0或者为负数的处理；
3. 我们所需要的长度一定是一个正数，所以只需要：x1 = (1 - 2*start + sqrt(discriminant)) / 2
4. 再计算discrimination时，需要注意，这里中间计算过程为int型会越界，所以这里强转为double；




### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 进行for循环，在起始位置固定，求解差值
        // （start + start + x - 1）* x /2 = target
        // x^2 + (2*start-1)*x  -2*target = 0;

        vector<vector<int>> result;
        vector<int> path;
        double x1 = 0;
        for(int start=1; start<=target/2; start++){
            double discriminant = (double)(2*start-1)*(2*start-1) + (double)8*target;
            if (0 < discriminant) {
                x1 = (1 - 2*start + sqrt(discriminant)) / 2;
                if(0<=x1 && x1==(int)x1) {
                    int i=0;
                    while(i<x1){
                        path.push_back(start + i);
                        i++;
                    }
                    result.push_back(path);
                    path.clear();
                    x1 = 0;
                }
             } else {
                continue;
            }
        }
        return result;
    }
};
```

提交：
![image.png](https://pic.leetcode-cn.com/03b03fa8cb45473e443e6469d4f3268cda8b94f4c805169b88038a49fd743c51-image.png)
