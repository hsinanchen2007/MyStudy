### 解题思路
直接-1，1对应着加，奇数就再加个0

### 代码

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int k=1;
        while(n>1){
            res.push_back(k);
            res.push_back(-k);
            k++;
            n-=2;
        }
        if(n%2==1) res.push_back(0);
        return res;
    }
};
```