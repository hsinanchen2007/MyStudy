递归的思想，到达4阶时候有一步到达和两步到达，一步到达（对应3阶），两步到达（对应2）阶，就是3阶方法个数加上2阶方法个数，同样5阶...n阶也是这样想
```
class Solution {
public:
    int climbStairs(int n) {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        if(n==1)
        return 1;
        if(n==2)
        return 2;
        int i;
        for(i=2;i<n;i++)
        {
           v.push_back(v[i-1]+v[i-2]);
        }
        return v[n-1];
    }
};
```
