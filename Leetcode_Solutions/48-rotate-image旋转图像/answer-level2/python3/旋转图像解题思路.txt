1. 首先观察图![image.png](https://pic.leetcode-cn.com/0845f49b329ea5f36b1a22d8fd558f5d09c506bc7fe3d9ee32edb1fb15900787-image.png)
2. 第一行旋转到最后一列，第二行旋转到倒数第二列，以此类推，易得 aij -> aj(n-1-i)
3. 再来一行行的交换需要额外的空间，可以由一个起点出发，一圈圈的换 如 1，3，9，7； 2，6，8，4
4. 只需要倒金字塔形的数据为起点(1,2,5)，将所有数据遍历一遍交换即可。交换过程中可将所有的点都交换到起点来，只需要O(1)的空间

下面是代码
```python3 []
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        aij  ->  aj(n-i+1)
         一圈一圈的往内，每一圈的第一个，四份之一的倒金字塔
        """
        n = len(matrix)
        for i in range((n+1)>>1):
            for j in range(i, n-i-1):
                next_i, next_j = j, n - i - 1 
                while (next_i != i or next_j != j):  # 当前没有走到起点的位置
                    matrix[next_i][next_j],matrix[i][j] = matrix[i][j],matrix[next_i][next_j] # 下一个位置与起点交换
                    next_j, next_i = n - next_i - 1, next_j # 下一个位置
                matrix[next_i][next_j],matrix[i][j] = matrix[i][j],matrix[next_i][next_j] # 最后一个位置与起点交换
                    
```
```C++ []
class Solution {
private:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0;i<(n>>1); i++)
            for (int j=i;j<n-i-1;j++) {
                int next_i = j;
                int next_j = n - i - 1;
                while (next_i != i || next_j != j) {
                    swap(matrix[i][j], matrix[next_i][next_j]);
                    int tmp = next_i;
                    next_i = next_j;
                    next_j = n - tmp - 1;
                }
                swap(matrix[i][j], matrix[next_i][next_j]);
            }
    }
};
```


