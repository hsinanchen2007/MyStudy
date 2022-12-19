需要多次求子矩阵之和，且矩阵的值不会再次修改，应该使用二维前缀和矩阵预处理，提高求和效率
具体参考：
[https://leetcode-cn.com/problems/range-sum-query-2d-immutable/](二维区域和检索 - 矩阵不可变)

使用二分查找可以提高查找效率，不过大部分测试案例的结果都较小，靠近下限，C++用顺序查找不会造成超时，看评论python会超。

代码如下：
```
class Solution {
public:
    vector<vector<int>> Pre;//保存前缀和
    int len1;
    int len2;

    int Fun(int len) {//找到所有对应边长的正方形的最小总和
        if (len == 0) return 0;
        int Min = 0x7fffffff;
        for (int i = 0; i < len1 - len + 1; ++i) {
            for (int j = 0; j < len2 - len + 1; ++j) {
                int tmp = Pre[i + len][j + len] - Pre[i + len][j] - Pre[i][j + len] + Pre[i][j];
                if (tmp < Min) Min = tmp;
            }
        }
        return Min;
    }

    int maxSideLength(vector<vector<int>> &mat, int threshold) {
        len1 = mat.size();
        len2 = mat[0].size();
        Pre = vector<vector<int>>(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                Pre[i][j] = Pre[i - 1][j] + Pre[i][j - 1] - Pre[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int Min = min(len1, len2);
        //二分查找，一般答案靠近下限，所以顺序查找效率也不低
        /*
        for(int i=0;i<=Min;++i){
            if(Fun(i)>threshold) return i-1;
        }
        return Min;
        */

        int lo = 0;
        int hi = Min;
        while (lo < hi) {
            int mi = (lo + hi + 1) >> 1;
            int k = Fun(mi);
            if (k <= threshold) {
                lo = mi;
            } else hi = mi - 1;
        }
        return lo;

    }
};
```
