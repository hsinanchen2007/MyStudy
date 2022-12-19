### 解题思路
for
    找到新的组
    判断元素数量
    添加到结果中
    更新每个组的起始索引

详细过程见注释。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;

        if (S.size() <= 2)
            return res;
        
        // 1. i 代表每个组的起始元素索引
        // 注意：本算法不能从 -1 开始，如果字符串只有一个组 "aaa"，则输出 [-1, 2]，与预期答案 [0, 2] 不符
        int i = 0;

        // 2. j 用来遍历数组和记录每个组的末端元素索引
        for (int j = 0; j < S.size(); j++) {
            // 3. 找到新的组，j == S.size() - 1 是为了防止遍历到最后一个元素时，S[j + 1] 索引溢出
            if (j == S.size() - 1 || S[j] != S[j + 1]) {
                
                // 4. 判断组内元素个数是否大于等于 3
                if (j - i + 1 >= 3)
                    res.push_back({i, j});

                // 5. 只要找到新的组，就更新 i 的值
                i = j + 1;
            }
        }

        return res;
    }
};
```