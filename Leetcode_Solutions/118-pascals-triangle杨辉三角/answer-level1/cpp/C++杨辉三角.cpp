### 解题思路
![1584786743353.jpg](https://pic.leetcode-cn.com/fb48476a7933efbc449a4d6fbfa324be8c31ec1fc5b7cc31986059fabe922757-1584786743353.jpg)
思路请看代码注释。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;

        // 初始化第一行
        vector<int> tmp{1};
        res.push_back(tmp);

        // 从第二行开始
        for(int i = 1; i < numRows; i++){
            tmp.resize(0);
            tmp.push_back(1);   // 第一个元素总是1

            // 从第二个元素开始
            // 注意这里的 i，i 表示当前行的索引，故第 i 行应该有 i + 1 个元素
            // 如：i = 2，代表当前在第三行，而第三行应有 3 个元素
            // 所以这一层的循环只会遍历到这一行元素的 第二 到 倒数第二 的位置
            for(int j = 1; j < i; j++){
                tmp.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            tmp.push_back(1);   // 最后一个元素总是1

            res.push_back(tmp);   // 将这一行的数组尾插至结果数组
        }

        return res;
    }
};
```