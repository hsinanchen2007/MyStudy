
### 代码

```cpp
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) 
    {
        if(ops.empty()) return m*n;//如果没有进行任何操作，那么每个元素都是 最大的元素

        //本题要看前几行和前几列一直被 操做 ，也就是求所有被 操作 的行[数和列数的最小值]()
        int a=INT_MAX,b=INT_MAX;
        for(vector<int> op:ops)
        {
            a=min(op[0],a);
            b=min(op[1],b);
        }
        return a*b;
    }
};
```