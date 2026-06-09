```
class Solution {
public:
    int tribonacci(int n) {
        int T[3] = {0, 1, 1}; // 使用定长数组
        if (n < 3) return T[n]; // 直接返回
        int num, index = -1; 
        for (int i=0; i<n-2; i++) {
            num = T[0] + T[1] + T[2]; // 计算泰波那契数
            index = (index + 1) % 3; // 更新idnex
            T[index] = num; // 替换掉旧值
        }
        return T[index];
    }
};
```

相比于使用`vector`，内存消耗减少了0.3M。
