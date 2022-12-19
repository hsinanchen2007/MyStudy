### 解题思路
一个有n个元素的序列，每次往后删除第m个元素：最后剩下的元素肯定在下标0的位置，那么这个元素在上一轮的位置应该是(0+m)%(上一轮元素个数)，依次往上推，得到在第一轮最后剩余元素的位置

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int   res=0;
        for(int i=2;i<=n;i++)
        {
            res=(res+m)%i;
        }
        return res;
    }
};
```