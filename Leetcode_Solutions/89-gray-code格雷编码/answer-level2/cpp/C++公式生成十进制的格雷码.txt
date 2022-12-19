### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i=0;i<pow(2,n);++i){
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};
```