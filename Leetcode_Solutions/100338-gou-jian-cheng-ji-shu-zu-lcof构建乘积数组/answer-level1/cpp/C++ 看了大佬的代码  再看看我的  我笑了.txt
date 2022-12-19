### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.empty())
            return {};
        int size = a.size();
        vector<int> x;
        vector<int> n(size,1);
        int temp = 1;
        for(int i =0;i<size;i++){
            temp *= a[i];
            x.emplace_back(temp);
        }
        temp = 1;
        for(int i = size - 1;i>=0;i--){
            temp *= a[i];
            n[i]=temp;
        }
        vector<int> res;
        res.emplace_back(n[1]);
        for(int i = 1;i<size-1;i++)
            res.emplace_back(x[i-1]*n[i+1]);
        res.emplace_back(x[size-2]);
        return res;
    }
};
```