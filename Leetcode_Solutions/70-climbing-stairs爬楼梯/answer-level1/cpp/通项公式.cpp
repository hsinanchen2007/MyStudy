### 解题思路
用通项公式双百
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n)
    {
        if(n==0)return 1;//可以不要这一句，但是就没有双百了
        return (pow((1+sqrt(5))/2,n+1)-pow((1-sqrt(5))/2,n+1))/sqrt(5);
    }
};
```