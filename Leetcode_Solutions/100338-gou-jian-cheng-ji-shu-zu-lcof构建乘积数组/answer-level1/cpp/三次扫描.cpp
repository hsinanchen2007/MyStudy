### 解题思路
- 正向扫描获取每个数左侧的乘积
- 反向扫描获取每个数右侧的乘积
- 最后扫描一遍得到除自身外的两侧乘积相乘

### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size(), i, product = 1;
        vector<int> left(n,1), right(n,1);
        for(i = 1; i < n; ++i)
        {
        	product *= a[i-1];
        	left[i] = product;
        }
        product = 1;
        for(i = n-2; i >= 0; i--)
        {
        	product *= a[i+1];
        	right[i] = product;
        }
        vector<int> ans(n);
        for(i = 0; i < n; ++i)
        	ans[i] = left[i]*right[i];
        return ans;
    }
};
```
更多解题
[https://blog.csdn.net/qq_21201267/article/details/100577842](https://blog.csdn.net/qq_21201267/article/details/100577842)