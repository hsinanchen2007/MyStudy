### 解题思路
动态规划，一般有递归求解方法。首先可写出递归方程或者递归解法，然后修改为非递归解法，即动态规划解法。
框架：1）在该题目中，假设已经知道了前n-1个房子的最佳花费，现在考虑第n个房子的粉刷方案。
细化：2）因为第n个房子有3种粉刷选择,所以有三种总花费。因为每一种选择的总花费都依赖于之前的总花费；准确的说是：第n个房子选择颜色0时，其总花费依赖于第n-1个房子选择颜色1时的总花费和选择颜色2时的总花费。
抽象：3）设第n-1个房子三种选择总花费分别为m0,m1,m2，则第n个房子的3种粉刷选择花费为：

m0 = min(m1+costs[n][0],m2+costs[n][0]);
m1 = min(m0+costs[n][1],m2+costs[n][1]);
m2 = min(m0+costs[n][2],m1+costs[n][2]);

则前n个房子的最佳花费为m=min(m0,m1,m2)。

### 代码

```cpp
class Solution {
public:
    int min3(int a,int b,int c){
        return min(min(a,b),c);
    }
    int minCost(vector<vector<int>>& costs)
    {
        if(costs.size()==0)
            return 0;

        if(costs.size()==1)
            return min3(costs[0][0],costs[0][1],costs[0][2]);
        
        vector<int> m;
        m ={costs[0][0],costs[0][1],costs[0][2]};

        for(int i=1;i<costs.size();i++){
            int minA =  min(m[1],m[2]) + costs[i][0];
            int minB =  min(m[0],m[2]) + costs[i][1];
            int minC =  min(m[0],m[1]) + costs[i][2];
            m={minA,minB,minC};
        }

        return min3(m[0],m[1],m[2]);
    }
  
};
```