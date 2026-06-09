### 解题思路
看了别的题解得到的启发，对于这种缺少第i项的整合，我们可以考虑从i出发，分别向左右搜索

### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> v(n, 1);
        int tms=1;
        int left = 1;
        for(int i = 0; i < n;i++){
            v[i] = left;
            left *= a[i];
        }
        int right =1;
        for(int i = n-1; i >= 0;i--){
            v[i] *= right;
            right *= a[i];
        }
        return v;
    }
};
```