### 分享一个比较少见的解题思路：2D的二分查找
- 对于每一个区域，如果取中心某个值作为基准和target比较，通过大小关系，我们可以直接去掉待排查区域的约1/4元素。
- 举例：
[
  [01, 04, 07, 11, 15],
  [02, 05, 08, 12, 19],
  [03, 06, 09, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
这个矩形的中心区域是9, 即matrix[2][2]

1. 假如我们要找9，那么OK；
2. 假如我们找的数比9大，那么我们可以把9的左边/上面/左上方的区域去掉（去掉的区域在下图中标成0，9自身也改成0，表示搜过了），剩下来的区域是：
[
  [00, 00, 00, 11, 15],
  [00, 00, 00, 12, 19],
  [00, 00, 00, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
可以发现：剩下来的区域可以拆成两个矩形，然后递归调用他们
3. 假如我们找的数比9大，那么我们可以把9的右边/下面/右下方的区域去掉（去掉的区域在下图中标成0，9自身也改成0，表示搜过了），剩下来的区域是：
[
  [01, 04, 07, 11, 15],
  [02, 05, 08, 12, 19],
  [03, 06, 00, 00, 00],
  [10, 13, 00, 00, 00],
  [18, 21, 00, 00, 00]
]
可以发现：剩下来的区域可以拆成两个矩形，然后递归调用他们

- 根据上面的分析，我们就可以写出一个递归调用的函数了。
- 从时间复杂度上看，我们每次能够去掉1/4的区域，那么是O(lg(mn)/lg(4/3))复杂度。因为拆分后的两个矩阵每一个都不超过原矩阵的一半大小，那么最大递归深度与 max(lgm, lgn)是一个数量级。（ **我这段分析可能是错的，如果有会分析的指点以下我:)** ）
- 代码如下：欢迎批评指正！ 运行36-56ms, 占用15.5MB-15.6MB

```cpp
class Solution {
private:
    bool binarySearch2D(const vector<vector<int>>& matrix, int stR, int enR, int stC, int enC, const int& target){
        if (stR > enR || stC > enC) return false;
        int midR = (stR + enR)/2;
        int midC = (stC + enC)/2;
        if (matrix[midR][midC] == target) return true;
        else{
            if (matrix[midR][midC] < target){
                return binarySearch2D(matrix, stR, enR, midC + 1, enC, target) || 
                    binarySearch2D(matrix, midR + 1, enR, stC, midC, target);
            }
            else{
                return binarySearch2D(matrix, stR, enR, stC, midC - 1, target) || 
                    binarySearch2D(matrix, stR, midR - 1, midC, enC, target);
            }
        }
    }

public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        return binarySearch2D(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, target);
    }
};
```
