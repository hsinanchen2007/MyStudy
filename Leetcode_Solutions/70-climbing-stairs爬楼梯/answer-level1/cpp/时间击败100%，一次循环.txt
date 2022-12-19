### 解题思路
此处撰写解题思路
利用数学规律：f[n]=f[n-1]+f[n-2]，使用数组组个计算，一次循环完成，时间复杂度为O(n)。
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int>vec(4,0);
        vec[1]=1;
        vec[2]=2;
        vec[3]=3;
        for(int i=4;i<=n;i++)
        {
            vec.push_back(0);
            vec[i]=vec[i-1]+vec[i-2];
        }
        return vec[n];
    }
};
```