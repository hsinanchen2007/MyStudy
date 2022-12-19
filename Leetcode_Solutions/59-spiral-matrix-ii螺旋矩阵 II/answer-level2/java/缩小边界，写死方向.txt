### 解题思路
此处撰写解题思路
类似第一版的旋转矩阵，这里旋转方向是写死的，但用缩小边界的方式，逐渐减小上下左右四个边界，做到能够停止收敛。
### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res=new int[n][n];
        int upper=0;
        int bottom=n-1;
        int left=0;
        int right=n-1;
        int i=0;
        int count=1;
        while(upper<=bottom)
        {
            while(i<=right)
            {
                res[upper][i]=count;
                count++;
                i++;
            }
            upper++;
            i=upper;
            while(i<=bottom)
            {
                res[i][right]=count;
                count++;
                i++;
            }
            right--;
            i=right;
            while (i>=left)
            {
                res[bottom][i]=count;
                count++;
                i--;
            }
            bottom--;
            i=bottom;
            while (i>=upper)
            {
                res[i][left]=count;
                count++;
                i--;
            }
            left++;
            i=left;

        }
        return res;
    }
}

```