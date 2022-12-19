### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        if(n == 0)
            return vector<int>();
        int upper = 10;
        while(--n)
            upper *= 10;
        // 初始化的时候确定vector的容量，避免扩容带来的开销
        vector<int> res(upper-1);
        for(int i = 1; i < upper; ++i)
            res[i-1] = i;
        return res;
    }
};
```