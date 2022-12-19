### 解题思路
利用vector容器
### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> arr;
        int a;
        a=pow(10,n);
        for(int i=1;i<a;i++){
            arr.push_back(i);
        }
        return arr;
    }
};
```