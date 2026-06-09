### 算法分析
1. 假设i = rowIndex, j表示列序号, res表示结果数组
2. res[0] = 1
3. res[j] = res[j - 1] * (i - j + 1) / j, j = 1 : i
### 复杂度分析
+ 时间复杂度：O(i)，i = rowIndex
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i = rowIndex;
        vector<int> res (i + 1, 1);
        long val = res[0];

        for (int j = 1; j < i; ++j)
        {
            val = val * (i - j + 1) / j;
            res[j] = (int)val;
        }
        
        return res;
    }
};