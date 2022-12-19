### 解题思路
dp也好,单调栈也好,差不多.其实都可以简化成这样
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = 0x7fffffff;
        int ret=0;
        for(int x:prices){
            low = low<=x?low:x;
            ret = max(ret,x-low);
        }
        return ret;
    }
};
```