### 解题思路
C++ 双100%
![a.PNG](https://pic.leetcode-cn.com/78ec0de120a9b8e0c7bef2afef0d581cbd782ed6c24c02b58d878c0da5f0ac8d-a.PNG)

### 代码

```cpp
/**
 * 矩阵旋转示例
 * [1,2,3]
 * [4,5,6]
 * [7,8,9]
 * 第一次旋转，把要旋转的行旋转，把写入旋转行后会被覆盖的元素写入到原旋转行的位置
 * 如，[2,3]会被[7,4,1]覆盖，则将[2,3]写到[7,4]原来的位置上
 * [7,4,1]
 * [2,5,6]
 * [3,8,9]
 * 第二次旋转，[6]会被[8,5,2]覆盖，则将[6]写到原来[8]的位置上
 * [7,4,1]
 * [8,5,2]
 * [3,6,9]
 * 最后得到结果
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int level = 0, col = 0; // 行，列索引
        while(level < matrix.size() && col < matrix[0].size()) {
            vector<int> tmp; // 要旋转的行
            vector<int> save; // 被旋转行覆盖要保存的其他元素
            for(int j = 0; j < col; j ++) {
                tmp.push_back(matrix[level][j]); // 取得为了避免被覆盖而保存的元素（如果有）
            }
            for(int i = level; i < matrix.size(); i ++) { // 取得要旋转的行
                tmp.push_back(matrix[i][col]);
            }
            for(int j = col + 1; j < matrix[0].size(); j ++) { // 取得旋转之后被覆盖的元素
                save.push_back(matrix[level][j]);
            }
            reverse(tmp.begin(), tmp.end()); // 需要旋转的那一行反转
            for(int j = 0; j < matrix[0].size(); j ++) { // 写入旋转行
                matrix[level][j] = tmp[j];
            }
            level += 1;
            for(int i = level; i < matrix.size(); i ++) { // 写入为了避免覆盖保存的元素
                matrix[i][col] = save[i - level];
            }
            col += 1;
        }
    }
};
```