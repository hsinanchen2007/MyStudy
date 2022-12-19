反正 $O(n^2)$ 也能过，就应该用最直白的做法暴力取最大值（并跑满 O(n^2)）！

```c++
class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        const int n = sat.size();
        
        int max = 0;
        for (int start = 0; start < n; start++) {
            int sum = 0;
            int time = 0;
            for (int i = start; i < n; i++) {
                time++;
                sum += time * sat[i];
            }
            
            if (sum > max) max = sum;
        }
        
        return max;
    }
};
```

思路就是所谓的“贪心”：尽量把满意度大的菜品放到后面做，但是满意度为负的有可能会舍弃一部分——因此需要暴力枚举，取最优解。