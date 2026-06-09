### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        vector<int> rec;
        rec.push_back(0);
        rec.push_back(1);
        int num=0;
        for(int i=2;i<=n;++i){
            num=rec[i-1]+rec[i-2];
            num%=1000000007;
            rec.push_back(num);
        }
        return rec[n];
    }
};
```