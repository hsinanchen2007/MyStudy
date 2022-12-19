### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int>a;
        for(int i=1;i<pow(10,n);++i){
            a.push_back(i);
        }
        return a;
    }
};
```