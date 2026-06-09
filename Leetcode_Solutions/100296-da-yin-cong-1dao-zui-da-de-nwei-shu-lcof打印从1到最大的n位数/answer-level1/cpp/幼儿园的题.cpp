### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        int t=pow(10,n);
        vector<int> ans;
        for(int i=1;i<t;i++){
            ans.push_back(i);
        }
        return ans;
    }
};
```