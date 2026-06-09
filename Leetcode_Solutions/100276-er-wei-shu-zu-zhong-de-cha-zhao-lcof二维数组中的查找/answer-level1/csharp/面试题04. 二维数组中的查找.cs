### 解题思路
C# 线性查找 O(m+n)

### 代码

```csharp
public class Solution {
    public bool FindNumberIn2DArray(int[][] matrix, int target) {
        int height = matrix.Length;
        if (height == 0) return false;
        int width = matrix[0].Length;
        // 从右上角开始
        int x = width - 1, y = 0;
        // 向左下角查找
        while (x >= 0 && y < height)
        {
            if (target < matrix[y][x])
            {
                // 如果当前坐标的数据大于目标值，X坐标向左移动
                x--;
            }
            else if (target > matrix[y][x])
            {
                // 如果当前坐标的数据小于目标值，Y坐标向下移动
                y++;
            }
            else
            {
                // 找到了
                return true;
            }
        }

        // 遍历数组仍未找到
        return false;
    }
}
```

### 解题思路
C# 二阶二分查找
此方法并不万年泉符合题意，因为并没有约束下一列的数字全部小于上一列的全部数字。
仅仅写在题解里分享下。

### 代码

```csharp
public class Solution {
    public bool FindNumberIn2DArray(int[][] matrix, int target)
    {
        int height = matrix.Length;
        if (height == 0) return false;
        int width = matrix[0].Length;
        int start = 0, end = width - 1;
        int halfWidth = 0, halfHeight = 0;
        while (start <= end)
        {
            halfWidth = start + (end - start) / 2;
            var currentValue = matrix[0][halfWidth];
            if (target < currentValue)
            {
                end = halfWidth - 1;
            }
            else if (target > currentValue)
            {
                if (halfWidth + 1 == width || target < matrix[0][halfWidth + 1])
                {
                    // 确定了所在的列
                    start = 0;
                    end = height - 1;
                    while (start <= end)
                    {
                        halfHeight = start + (end - start) / 2;
                        currentValue = matrix[halfHeight][halfWidth];
                        if (target < currentValue)
                        {
                            end = halfHeight - 1;
                        }
                        else if (target > currentValue)
                        {
                            start = halfHeight + 1;
                        }
                        else
                        {
                            return true;
                        }
                    }
                    return false;
                }
                else
                {
                    start = halfWidth + 1;
                }
            }
            else
            {
                // 在第一行找到了
                return true;
            }
        }

        return false;
    }
}
```