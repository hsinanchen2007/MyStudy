### 解题思路
C++，逐层构造
![WeChat7a19170f1cfa77466d446972aece9d1b.png](https://pic.leetcode-cn.com/8e9f30df59c2a59bb6c83ade824446d015faa25f20f0e4e11d07cbf534c21ac6-WeChat7a19170f1cfa77466d446972aece9d1b.png)
### 代码
```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> tmp, res{1};   // 初始化
        for(int i = 1; i <= rowIndex; i++){
            // tmp存当前索引行的数据，res存上一行的数据
            tmp.resize(0);
            tmp.push_back(1);
            for(int j = 1; j < i; j++){
                tmp.push_back(res[j-1] + res[j]);
            }
            tmp.push_back(1);
            res = tmp;
        }
        return res;
    }
};
```