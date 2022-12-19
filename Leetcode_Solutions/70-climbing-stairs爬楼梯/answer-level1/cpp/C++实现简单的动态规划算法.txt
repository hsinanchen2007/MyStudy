### 解题思路
此处撰写解题思路
    首先处理一些边界情况，n=0,1,2时的值显然，可以直接返回，后面的可以用动态规划算法得出结果
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int *ways=new int[n+1];
        ways[0]=0;
        ways[1]=1;
        ways[2]=2;
        for(int i=3;i<=n;i++){
            ways[i]=ways[i-1]+ways[i-2];
        }
        return ways[n];
    }
};
```