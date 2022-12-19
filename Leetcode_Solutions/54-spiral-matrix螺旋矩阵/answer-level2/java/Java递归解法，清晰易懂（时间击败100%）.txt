![image.png](https://pic.leetcode-cn.com/fbed4c77ce4098c780843ed279e80f46c8830d8506313f2f16c756c3b7b296e7-image.png)



# 顺时针打印矩阵，其实可以把这个问题分解。

1.  顺时针打印当前矩阵最外围的一圈
2.  打印内部的子矩阵 (将子矩阵作为当前矩阵跳转到(1))


所以这个问题可以递归求解，每次打印当前的矩阵最外围一圈的点。

```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        int height = matrix.length;         // 获取矩阵从上到下的长度
        if (height == 0) return list;
        int width = matrix[0].length;       // 获取矩阵从左到右的长度
        if (width == 0) return list; 
    
        return helper(matrix, list, 0, width-1, 0, height-1);
    }

    // 对于绕一圈走外围这种问题，通常把边角的点统一算在横向或者竖向。避免重复或者遗漏
    public List<Integer> helper(int[][] matrix, List<Integer> list, int left, int right, int up, int down) {
        if (left>right || up>down) return list; 
        for (int i=left; i<=right; i++) {   // 横向算了边角的点
            list.add(matrix[up][i]);
        }
        for (int i=up+1; i<=down-1; i++) {  // 竖向不算边角的点
            list.add(matrix[i][right]);
        }
        if (up < down) {
            for (int i=right; i>=left; i--) {  // 横向算了边角的点
                list.add(matrix[down][i]);
            }
        }
        if (left < right) {
            for (int i=down-1; i>=up+1; i--) {   // 竖向不算边角的点
                list.add(matrix[i][left]);
            }
        }
        return helper(matrix, list, left+1, right-1, up+1, down-1);  // 递归解决子矩阵
    }
}
```
