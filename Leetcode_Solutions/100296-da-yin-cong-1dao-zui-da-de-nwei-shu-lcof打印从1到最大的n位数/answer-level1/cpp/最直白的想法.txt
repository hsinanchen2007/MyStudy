

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;

        for(int i=1;i<pow(10,n);i++)
            res.push_back(i);

        return res;
    }
};
```