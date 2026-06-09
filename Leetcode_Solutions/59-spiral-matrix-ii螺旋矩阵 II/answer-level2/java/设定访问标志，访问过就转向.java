### 解题思路
设定flag[n][n]数组，每次往result[i][j]中填写好元素，就设置flag[i][j]=1,遇到flag[i][j]=1就转向，向右->向下->向左->向上->向右...

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int[][] flag = new int[n][n];
        int i = 0;
        int j = 0;
        int count = 1;
        int top = n * n;
        //count 表示填充的个数
        while (count <= top){
            //往右
            while (j < n){
                if (flag[i][j] == 0){
                    result[i][j] = count++;
                    flag[i][j++] = 1;
                }
                else
                    break;
            }
            j--;
            i++;
            //往下
            while (i < n){
                if (flag[i][j] == 0){
                    result[i][j] = count++;
                    flag[i++][j] = 1;
                }
                else
                    break;
            }
            i--;
            j--;
            //往左
            while (j >= 0){
                if (flag[i][j] == 0){
                    result[i][j] = count++;
                    flag[i][j--] = 1;
                }
                else
                    break;
            }
            j++;
            i--;
            //往上
            while (i >= 0){
                if (flag[i][j] == 0){
                    result[i][j] = count++;
                    flag[i--][j] = 1;
                }
                else
                    break;
            }
            i++;
            j++;
        }
        return result;
    }
}
```