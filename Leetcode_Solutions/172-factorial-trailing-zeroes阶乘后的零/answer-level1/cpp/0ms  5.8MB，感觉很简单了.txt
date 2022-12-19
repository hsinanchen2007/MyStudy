### 解题思路
我感觉写的很简单了

### 代码

```cpp
class Solution {
public:
    int trailingZeroes(int n)
    {
        int sum=0;
        while(n!=0)
        {
            n/=5;
            sum+=n;
        }
        return sum;
    }
    
};
```