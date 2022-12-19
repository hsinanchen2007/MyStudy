### 解题思路
纯数学解法
1. 每个m*n的方格可以划为若干个10*10的方格，对每个方格，考察右上角和左下角位置机器人是否能通过，如果能通过，则继续往右侧搜寻
2. 对于每个方格，如果上方或左侧的方格不通，则此方格无法到达
3. 计算每个可通的方格内部的可达坐标数量，注意边界条件
4. 代码丑了点，画个图就知道了

### 代码

```java
class Solution {
    

    public int m,n;
    public int movingCount(int m, int n, int k) {
        this.m = m;
        this.n = n;
        // 每个m*n的方格可以划为x个10*10的方格，计算横向和纵向每个方格是否能同行
        int iBlocks = m / 10 + (m % 10 == 0 ? 0 : 1);
        int jBlocks = n / 10 + (n % 10 == 0 ? 0 : 1);
        int[][] passFlag = new int[iBlocks][];
        for (int i = 0; i < iBlocks; i++) {
            passFlag[i] = new int[jBlocks];
        }
        int result = 0;
        for (int i = 0; i < iBlocks ; i++) {
            for (int j = 0; j < jBlocks ; j++) {
                if ((i > 0 && passFlag[i - 1][j] > 0) || (j > 0 && passFlag[i][j - 1] > 0)) {
                    passFlag[i][j] = 1;
                    break;
                }
                int area = area(i , j , k);
                if (area < 0) {
                    result += -area;
                    passFlag[i][j] = 1;
                    break;
                }else {
                    result += area;
                }
            }
        }

        return result;
    }

    public int area(int i, int j, int k) {
        int maxI = Math.min(10 * (i + 1) - 1, m - 1);
        int maxJ = Math.min(10 * (j + 1) - 1, n - 1);
        boolean passRU = i + j + maxJ % 10 <= k;
        int iLength = maxI - 10 * i + 1;
        int jLength = maxJ - 10 * j + 1;
        boolean passLD = i + j + maxI % 10 <= k;
        int passLength = k - i - j + 1;
        if (passLD && passRU) {
            // 右下三角
            int ix = k + 1 - i - j - maxJ % 10;
            ix = ix > 9 || ix > maxI % 10 ? 0 : iLength - ix;
            int jx = k + 1 - i - j - maxI % 10;
            jx = jx > 9 || jx > maxJ % 10 ? 0 : jLength - jx;
            int bottom = Math.max(ix, jx);
            int height = Math.min(ix, jx);
            return iLength * jLength - (2 * bottom - height + 1) * jx / 2;
        } else if(!passLD && !passRU){
            // 左上三角
            return -passLength * (passLength + 1) / 2;
        }else if (!passLD && passRU) {
            // 左下不能通过，右上能通过，最后一列
            return -(passLength + Math.max(0, passLength - jLength) + 1) * jLength / 2;
        } else {
            return -(passLength + Math.max(0, passLength - iLength) + 1) * iLength / 2;
        }
    }
}
```