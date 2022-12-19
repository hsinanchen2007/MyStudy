不废话，看代码就懂了：
```
class Solution {
public:
    int getSum(int a, int b) {
        vector<int> x({a,b});
        return accumulate(x.begin(), x.end(), 0);
    }
};
```
