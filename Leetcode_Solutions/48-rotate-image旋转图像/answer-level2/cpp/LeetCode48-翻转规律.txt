## 翻转的规律
矩阵操作名词说明： 
对角线 ：按着左上到右下的对角线翻转  `\`
反对角线：按着右上到左下的对角线翻转 `/`
竖轴：按着平行于y轴的中心线翻转 `|`
横轴： 按着平行于x轴的中心线翻转 `——`
90°：矩阵顺时针旋转90°
180°：矩阵顺时针旋转180°
279°：矩阵顺时针旋转270°

### 矩阵翻转规律如下

```
对角线 + 竖轴 = 90° 
对角线 + 横轴 = 270°

反对角线 + 竖轴 = 270°
反对角线 + 横轴 = 90°

横轴 + 竖轴 = 180°
```

### 解题思路
所以本题可以使用两种方法进行翻转
方法一： 对角线 + 竖轴 = 90° 
方法二： 反对角线 + 横轴 = 90°

### 方法一代码
* 对角线 + 竖轴 = 90° 
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // 对于正对角线对称翻转
        for (int i = 0; i < n; i++) {
            for (int j = i; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 竖轴镜像操作
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

### 方法二代码
* 反对角线 + 横轴 = 90°
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // 对于反正对角线对称翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1-i; j++) {
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }
        // 横轴镜像操作
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n/2; i++) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
    }
};
```