### 解题思路
![image.png](https://pic.leetcode-cn.com/8a69eda06b184736192756e092cc49a09a7948d0d2360e30304d74e6b235b6c8-image.png)


### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>v(n,1);    
        while(--m)for(int i=1;i<n;++i) v[i]+=v[i-1];         
        return v[n-1];
    }
};
```