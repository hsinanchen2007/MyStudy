

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        int last = pow(10,n)-1;
        vector<int> res;
        int i=1;
        while(i<=last){
            res.push_back(i);
            i++;
        }
        return res;
    }
};
```